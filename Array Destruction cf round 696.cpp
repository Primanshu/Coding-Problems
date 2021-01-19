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
    const int mxn=2e6+7;
    int arr[mxn];
    multiset<int> st;
    vc<pi> ans;
    int n;
     
    bool solve(multiset<int> &cpy, int mx) {
        while(!cpy.empty()) {
            int sum = mx;
            //take the maximum element
            multiset<int>::reverse_iterator itr = cpy.rbegin();
            mx = *itr;
            cpy.erase(cpy.find(mx));
            if(cpy.find(sum - mx) == cpy.end()) {
                break;
            } else {
                cpy.erase(cpy.find(sum-mx));
                ans.pb({mx,sum-mx});
            }
        }
        if(ans.size() == n/2) {
            cout<<"YES\n";
            cout<<ans.front().first + ans.front().second<<"\n";
            for(auto el : ans )
                cout<<el.first<<" "<<el.second<<"\n";
            return true;
        }
        return false;
    }
     
    void tc() {
        cin>>n;
        n*=2;
        st.clear();
        fr(i,1,n+1) {
            cin>>arr[i];
            st.ins(arr[i]);
        }
        sort(arr+1,arr+1+n);
        ans.clear();
        for(int i=1; i<n; i++) {
            ans.pb({arr[i],arr[n]});
            multiset<int> cpy(st);
            cpy.erase(cpy.find(arr[n]));
            cpy.erase(cpy.find(arr[i]));
            if(solve(cpy,arr[n]))
                return;
            ans.clear();
        }
        cout<<"NO\n";
    }
    int32_t main() {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int t; t=1;
        cin>>t;
        while(t--)  tc();
    }
