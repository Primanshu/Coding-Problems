    #include <bits/stdc++.h>
    using namespace std;   
    const int mod = 1e9 + 7;
    #define inf 1e16
    #define pb push_back
    #define ins insert
    #define vc vector
    #define umap unordered_map
    #define uset unordered_set
    #define int long long int
    #define pi pair<int, int>
    #define ld long double
    #define ff first
    #define ss second
    #define all(x) x.begin(), x.end()
    #define fr(i, a, n) for (int i = a; i < n; i++)
    #define frr(i, a, n) for (int i = n - 1; i >= a; i--)
    #define file_in freopen("a.txt", "r", stdin);
    const int mxn=1e6;
     
    int power(unsigned long long x, 
                                      int y, int p)
    {
        unsigned long long res = 1; // Initialize result
     
        x = x % p; // Update x if it is more than or
        // equal to p
     
        while (y > 0) 
        {
         
            // If y is odd, multiply x with result
            if (y & 1)
                res = (res * x) % p;
     
            // y must be even now
            y = y >> 1; // y = y/2
            x = (x * x) % p;
        }
        return res;
    }
     
    int modInverse(unsigned long long n,  
                                                int p)
    {
        return power(n, p - 2, p);
    }
     
    int nCrModPFermat(unsigned long long n,
                                     int r, int p)
    {
        // If n<r, then nCr should return 0
        if (n < r)
            return 0;
        // Base case
        if (r == 0)
            return 1;
     
        // Fill factorial array so that we
        // can find all factorial of r, n
        // and n-r
        unsigned long long fac[n + 1];
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = (fac[i - 1] * i) % p;
     
        return (fac[n] * modInverse(fac[r], p) % p
                * modInverse(fac[n - r], p) % p)
               % p;
    }
     
    void tc() {
        int n; cin>>n;
        int k; cin>>k;
        int arr[n];
        fr(i,0,n)
            cin>>arr[i];
        sort(arr,arr+n);
        int ans = 1;
        //kth el from end
        int el = (n-1) - k +1;
        el = arr[el];
        int tot = 0;
        int pos = 0;
        for(int i = (n-1-k+1); i<n; i++) {
            if(arr[i] == el)
                pos++;
        }
        // cout<<"el - "<<el<<"\n";
        for(int i=0; i<n; i++) {
            if(arr[i] == el) {
                tot++;
            }
        }
        // cout<<"tot - "<<tot<<" , pos - "<<pos<<"\n";
        ans = nCrModPFermat(tot,pos,mod);
        cout<<ans<<"\n";
    }
    int32_t main() {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int t; t=1;
        cin>>t;
        while(t--)  tc();
    }
