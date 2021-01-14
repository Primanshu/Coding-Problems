    #include <bits/stdc++.h>
    using namespace std;   
    #define mod 998244353
    #define inf 1e16
    #define pb push_back
    #define ins insert
    #define vc vector
    #define umap unordered_map
    #define uset unordered_set
    #define int long int
    #define pi pair<int, int>
    #define ld long double
    #define ff first
    #define ss second
    #define all(x) x.begin(), x.end()
    #define fr(i, a, n) for (int i = a; i <= n; i++)
    #define frr(i, a, n) for (int i = n - 1; i >= a; i--)
    #define file_in freopen("a.txt", "r", stdin);
    const int mxn=2e5+7;
     
    int n;
     
    // ***************************************DSU**********************************
    //initialisation of , parent and size array
    //use node as 1 based, not zero based
    vc<int> p ,sz;
    void init(int n) {
        p.assign(n+3,-1);
        sz.assign(n+3,1);
    }
    //finding the root of the component
    int root(int x) {
        if(p[x] == -1) return x;
        return p[x] = root(p[x]); //path compression
    }   
    //merge two nodes in one component
    void Union(int a , int b) {
        int par_a = root(a);
        int par_b = root(b);
        if(par_a == par_b) return; 
        if(sz[par_a] < sz[par_b])  
            swap(a,b);
        sz[par_a] += sz[par_b];
        p[par_b] = par_a;
    }
    //check two nodes are in same component
    bool connected(int a ,int b) {
        return root(a) == root(b);
    }
     
    // ****************************************SIEVE****************************************
    //contain all the prime numbers, 1st=-1,2nd = 2 ,3rd = 3, 4th = 5 ....
    vc<int> prime;
    vc<int> sp; //smallest prime divisor of i = sp[i]
    bool isprime[mxn+3]; //checking if a number is prime or not
    void sieve() {
        prime.clear();
        sp.assign(mxn+3,-1);
        for(int i=1; i<=mxn; i++) {
            sp[i] = i;
        }
        sp[2] = 2;
        prime.pb(-1);
        memset(isprime,true,sizeof isprime);
        for(int i=2; i*i<=mxn; ++i)  {
            if(isprime[i]) {
                sp[i] = i;
                for(int j=i*i; j<=mxn; j+=i) {
                    if(sp[j]==j)
                        sp[j] = i;
                    isprime[j] = false;
                }
            }
        }
        fr(i,2,mxn) {
            if(isprime[i]){
                prime.pb(i);
            }
        }
    }
     
     
    // ********************************RMQ***************************************
    //use zero based indexed array, [L,R] => [0,n-1]. INCLUSIVE
    //K = ceil(log(mxn)). mxn - maxm size of the array
    int logg[mxn+1];
    struct RMQ {
        static const int K = 21;
        int st[mxn][K + 1];
     
        void precalc() {
            logg[1] = 0;
            for (int i = 2; i <= mxn; i++)
            logg[i] = logg[i/2] + 1;
        }
        void calc(int N,int * array)  {
            for (int i = 0; i < N; i++)
                st[i][0] = array[i];
            for (int j = 1; j <= K; j++)
                for (int i = 0; i + (1 << j) <= N; i++)
                    st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
        }  
     
        int query(int L , int R) {
            int j = logg[R - L + 1];
            int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
            return minimum;
        }
    } rmq;
     
    //************************************BIT*************************************
    //single point update
    //specify 'n' globally
     
    vc<int> bit;
    void update(int idx , int val) {
        while(idx<=n) {
            bit[idx]+=val;
            idx += idx & -idx;
        }
    }
    int sum (int idx) {
        int res = 0;
        while(idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }
     
    void buildTree(int *tree,int *a,int index,int s,int e)
    {
    	//base case
    	if(s>e)
    		return;
    	//reached leaf node
    	if(s==e)
    	{
    		tree[index]=a[s];
    		return ;
    	}
    	//now build the segment tree in bottom up manner
    	int m = (s+e)/2;
    	buildTree(tree,a,2*index,s,m);
    	buildTree(tree,a,2*index+1,m+1,e);
    	tree[index]= max(tree[2*index],tree[2*index+1]);
    	return;
    }
     
    //function to query the segment tree for RMQ
    int query(int *tree,int index,int s,int e,int qs,int qe)
    {
    	//base case: if query range is outside the node range
    	if(qs>e || s>qe)
    		return INT_MIN;
    	//complete overlap
    	if(s>=qs && e<=qe)
    		return tree[index];
    	//now partial overlap case is executed
    	int m = (s+e)/2;
    	int left_ans = query(tree,2*index,s,m,qs,qe);
    	int right_ans = query(tree,2*index+1,m+1,e,qs,qe);
    	return max(left_ans,right_ans);
    }
     
     
     
     
    void tc() {
        int q; cin>>n>>q;
        string s; cin>>s;
        int mn = 0,mx = 0;
        int x = 0;
        vc<pair<int,int>> mm; //mn , mx at each pt
        bit.assign(n+2,0);
        int arr[n];
        fr(i,0,n-1) {
            int val;
            if(s[i]=='+') 
                x++,val=1;
            else 
                x--,val=-1;
            mn = min(mn,x);
            mx = max(mx,x);
            mm.pb({mn,mx});
            update(i+1,val);
            arr[i] = x;
        }
     
        rmq.calc(n,arr);
     
        //max  queries
        int tree[4*n + 3];
        buildTree(tree,arr,1,0,n-1);
     
        while(q--) {    
            int l,r; cin>>l>>r;
            mn = 0; mx = 0;
            int effect = sum(r) - sum(l-1);
            --l , --r;
            if(l>0)
                mn = mm[l-1].first , mx = mm[l-1].second;
            if(r+1<n) {
                int minn = rmq.query(r+1,n-1) - effect;
                int maxx = query(tree,1,0,n-1,r+1,n-1) - effect;
                mn = min(mn,minn);
                mx = max(maxx,mx);
            }
            cout<<mx-mn+1<<"\n";
        }
    }
    int32_t main() {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int t; t=1;
        rmq.precalc();
        cin>>t;
        while(t--)  tc();
    }
