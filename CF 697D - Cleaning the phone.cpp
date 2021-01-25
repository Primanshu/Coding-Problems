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
        int n; cin>>n;
        int m; cin>>m;
        vc<int> a1 ; vc<int> a2 , p1(1,0) , p2(1,0);
        vc<int> arr;
        int x;
        fr(i,0,n) {
            cin>>x;
            arr.pb(x);
        }
     
        fr(i,0,n) {
            cin>>x;
            if(x==1)
                a1.pb(arr[i]);
            else 
                a2.pb(arr[i]);
        }
        sort(all(a1),greater<int>());
        sort(all(a2),greater<int>());
     
        if(!a1.empty()) {
            for(auto el : a1)
                p1.pb(el);
        }
        if(!a2.empty()) {
            for(auto el : a2)
                p2.pb(el);
        }
     
        for(int i=1; i<p1.size(); i++) {
            p1[i] += p1[i-1];
        }
        fr(i,1,p2.size()) {
            p2[i] += p2[i-1];
        }
     
        int sz1 = a1.size();
        int ans = inf;
        fr(take , 0 , sz1+1) {
            int remaining = m - p1[take];
            if(remaining <= 0) {
                ans = min(ans , take);
            }
            int pos = lower_bound(all(p2) , remaining) - p2.begin();
            if(pos == p2.size()) --pos;
            remaining -= p2[pos];
            if(remaining <= 0) {
                ans = min(ans , take + 2*pos);
            }
        }
        if(ans == inf) {
            ans = -1;
        }
        cout<<ans<<"\n";
    }
    int32_t main() {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int t; t=1;
        cin>>t;
        while(t--)  tc();
    }
