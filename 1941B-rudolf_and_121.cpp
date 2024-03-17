#include<iostream>
#include <vector>
#include <algorithm>
#define int long long int
using namespace std;

bool all_zero(int * arr, int n) {
    bool ans = true;
    for(int i=1; i<=n; i++){
        ans = ans && (arr[i] == 0);
    }
    return ans;
}

void make_zero(int *arr, int n, bool front=false) {

    int index = 2;
    int change = 1;
    if(!front){
        index = n-1;
        change = -1;
    }

    int left, right;
    for(index; index>=2 && index<=n-1; index = index + change) {
        left = arr[index - 1];
        right = arr[index + 1];

        if(left<1 or right<1 or arr[index]<2)
            continue;
        
        int minElement = min(left, right);
        int numberOf2Operations = arr[index]/2;

        int numberOfOperations = min(minElement, numberOf2Operations);
        arr[index] = arr[index] - numberOfOperations*2;
        arr[index - 1] -= numberOfOperations;
        arr[index + 1] -= numberOfOperations;
    }
}

void test_case() {
    int n;
    cin>>n;
    int arr[n+1];
    int arr2[n+1];

    for(int i=1; i<=n; i++) {
        cin>>arr[i];
        arr2[i] = arr[i];
    }

    make_zero(arr, n);
    make_zero(arr2, n, true);

    if(all_zero(arr,n) or all_zero(arr2, n)){
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }
}


int32_t main() {
    int t = 1; 
    cin>>t;
    while(t--)
        test_case();
}