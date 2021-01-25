    #include <bits/stdc++.h>
    using namespace std;   
    #define mod 998244353
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
     
    void tc() {
        int a,b,k; cin>>a>>b>>k;
        vc<int> by(a+1,0) , gi(b+1,0);
        vc<pi> v;
        vc<int> a1 , a2;
        fr(i,0,k) {
            int x;
            cin>>x;
            by[x]++;
            a1.pb(x);
        }
        fr(i,0,k) {
            int x; cin>>x;
            gi[x]++;
            a2.pb(x);
        }
        int ans = 0;
        bool ok = false;
        int x,y;
        fr(i,0,k) {
            x = a1[i];
            y = a2[i];
            int tmp = k - by[x] - gi[y] + 1;
            ans = ans + tmp;
            // if(!ok and ans%2==0) {
            //     ans /= 2;
            //     ok = true;
            // }
        }
        if(!ok) {
            ans /= 2;
        }
        cout<<ans<<"\n";
    }
    int32_t main() {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int t; t=1;
        cin>>t;
        while(t--)  tc();
    }
