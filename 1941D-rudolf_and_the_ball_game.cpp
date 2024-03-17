#include<iostream>
#include <vector>
#include <algorithm>
#include<set>
#define int long long int
using namespace std;

void test_case() {
    int n,m,x;
    int position = x;

    int dis; 
    char ch;
    vector<int> distance(0);

    for(int i=0; i<m; i++) {
        cin>>dis>>ch;
        if(ch == '1') { //anti-clock
            position = (position - dis + n)%n;
            if(position == 0)
                position = n;
        } else if (ch == '0'){
            position = (position + dis) %n;
            if (position == 0) position = n;
        } else{
            distance.push_back(dis);
        }
    }

    set<int> end;
    end.insert(position);

    for(int i=0; i<distance.size(); i++) {
        dis = distance[i]; //clock or a-clock
        set<int> end2;

        for(int element : end) {
            position = (element + dis)%n;
            if(position == 0)   position = n;
            end2.insert(position);
            position = (element - dis + n) % n;
            if(position == 0) position = n;
            end2.insert(position);
        }

        end = end2;
    }

    int ans = end.size();
    cout<<ans<<"\n";
    for(int element : end) {
        cout<<element<<" ";
    }
    cout<<"\n";
}


int32_t main() {
    int t = 1; 
    cin>>t;
    while(t--)
        test_case();
}