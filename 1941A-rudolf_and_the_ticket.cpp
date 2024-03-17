#include<iostream>
#include <vector>
#include <algorithm>
#define int long long int
using namespace std;

void test_case() {
    int n,m,k;
    cin>>n>>m>>k;

    int arr[n], arr2[m];
    for(int i=0; i<n; i++) 
        cin>>arr[i];
    for(int i=0; i<m; i++) 
        cin>>arr2[i];
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i] + arr2[j] <= k){
                // cout<<"el1: "<<arr[i]<<" el2: "<<arr2[j]<<"\n";
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}


int32_t main() {
    int t = 1; 
    cin>>t;
    while(t--)
        test_case();
}