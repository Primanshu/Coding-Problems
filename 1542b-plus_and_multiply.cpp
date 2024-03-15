#include<iostream>
using namespace std;
#define int long long int


void tc() {
    int n,a,b;
    cin>>n>>a>>b;

    int power_of_a = 1;
    
    if(b == 1) {
        cout<<"Yes\n";
        return;
    }

    for(int i=1; true; i++) {
        int z = n - power_of_a;
        if(z<0)
            break;

        if(z%b == 0){
            cout<<"Yes\n";
            return;
        }

        power_of_a*=a;
        if(a == 1)
            break;
    }
    cout<<"No\n";
}

int32_t main() {
    int t; 
    cin>>t;
    while(t--)
        tc();
}