#include<iostream>
#include<algorithm>
using namespace std;
#define int long long int

pair<int,int> binary_search(int n, int k) {
    int left = 0,  right = n-2;
    int ans = -1; //this contains the string combination number 
    int number_of_a = -1;

    while(left <= right) {
        int mid = (left + right)/2;
        // cout<<"left: "<<left<<" mid: "<<mid<<" right: "<<right<<"\n";
        int value = (mid * (mid +1)) / 2;
        if (value < k) {
            ans = max(ans , value);
            number_of_a = max(number_of_a, mid);
            left = mid + 1;
        } else 
            right = mid-1;
    }

    return make_pair(number_of_a, ans);
}

void tc() {
    int n,k;
    cin>>n>>k;

    pair<int,int> a_and_string_index = binary_search(n,k);
    // cout<<"Binary search completed\n";
    int number_of_a = a_and_string_index.first;
    int string_index = a_and_string_index.second + 1;

    int positions_by_which_b_should_be_moved = k - string_index;
    int final_number_of_a_between_b = number_of_a - positions_by_which_b_should_be_moved;
    int position_of_first_b = n - number_of_a - 1;
    int position_of_second_b = position_of_first_b + final_number_of_a_between_b + 1;

    for(int i=1; i<=n; i++) {
        if(i==position_of_first_b or i==position_of_second_b) {
            cout<<'b';
        } else 
            cout<<'a';
    }
    cout<<"\n";

}

int32_t main() {
    int t;
    cin>>t;

    while(t--) {
        tc();
    }
}