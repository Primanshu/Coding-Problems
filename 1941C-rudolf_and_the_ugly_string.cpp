#include<iostream>
#include <vector>
#include <algorithm>
#define int long long int
using namespace std;

bool check_valid_word(string str) {
    return str == "map" or str == "pie";
}

void mark_occurrence(string& s, vector<int>& occurrence) {
    int n = s.length();
    // cout<<"n: "<<n<<"\n";
    for(int i=0; i<n-2; i++) {
        // cout<<"Got inside for..\n";
        bool found = check_valid_word(s.substr(i,3));
        if(found) {
            occurrence[i]++;
            occurrence[i+1]++;
            occurrence[i+2]++;
        }
    }
}

int count_occurrences(vector<int> & occurrence) {
    int n = occurrence.size();
    int ans = 0;
    for(int i=0; i<n-2; i++) {
        if(occurrence[i]>0 and occurrence[i+1]>0 and occurrence[i+2]>0) {
            ans++;
            if(occurrence[i+2] == 2)
                i+=4;
            else 
                i+=2;
        }
    }
    return ans;
}

void print_occurrences(vector<int>& occurrences) {
    int n = occurrences.size();
    cout<<"Printing.. \n";
    for(int i=0; i<n; i++) {
        cout<<occurrences[i]<<", ";
    }
    cout<<"\n";
}

void test_case() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> occurrence(n+1, 0);
    mark_occurrence(s, occurrence);
    int ans = count_occurrences(occurrence);
    // print_occurrences(occurrence);
    cout<<ans<<"\n";
}


int32_t main() {
    int t = 1; 
    cin>>t;
    while(t--)
        test_case();
}