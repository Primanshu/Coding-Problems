#include <bits/stdc++.h>
using namespace std;
    
#define M 998244353
#define inf 1e13
#define pb push_back
#define ff first
#define ss second
#define int long long int
#define ld long double
#define pi pair<li, li>
#define ins insert
#define vc vector
#define umap unordered_map
#define uset unordered_set
#define all(x) x.begin(), x.end()
#define fr(i, a, n) for (int i = a; i < n; i++)
#define frr(i, a, n) for (int i = n - 1; i >= a; i--)
#define file_in freopen("a.txt", "r", stdin);
const int mxn=1e6;
int dp[4005][4005];
int n,k;
int arr[4005];

int solve(int idx , int h1 , int sum) {
    int h2 = sum - h1;
    // cout<<"idx - "<<idx<<" , h1 - "<<h1<<" , h2 - "<<h2<<"\n";
    if(h1 >= k and h2 >= k)
        return 0;
    if(idx >= n) {
        if(h1>=k and h2>=k)
            return 0;
        return inf;
    }
    if(dp[idx][h1]!=-1)
        return dp[idx][h1];
    int ans = inf;
    if(h1 < k)
        ans = min(ans , 1 + solve(idx+1 , h1+arr[idx] , sum+arr[idx]));
    if(h2 < k)
        ans = min(ans , 1 + solve(idx+1 , h1 , sum+arr[idx]));
    return dp[idx][h1] = ans;
}

void tc() {
    cin>>n>>k;
    memset(dp,-1,sizeof dp);
    fr(i,0,n) cin>>arr[i];
    sort(arr,arr+n,greater<int>());
    // fr(i,0,n) cout<<arr[i]<<" "; cout<<"]\n";
    int ans = solve(0,0,0);
    if(ans >= inf) {
        cout<<-1<<"\n";
    } else 
        cout<<ans<<"\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; t=1;
    cin>>t;
    while(t--)  tc();
}
