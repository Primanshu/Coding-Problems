#include <bits/stdc++.h>
using namespace std;   
#define mod 998244353
#define inf 1e16
#define ff first
#define umap unordered_map
#define uset unordered_set
#define pb push_back
#define ins insert
#define vc vector
#define ld long double
#define int long long int
#define pi pair<int, int>
#define ss second
#define all(x) x.begin(), x.end()
#define fr(i, a, n) for (int i = a; i < n; i++)
#define frr(i, a, n) for (int i = a; i >= n; i--)
#define file_in freopen("a.txt", "r", stdin);
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
const int mxn=1e6;

// ********************************RMQ***************************************
//use zero based indexed array, [L,R] => [0,n-1]. INCLUSIVE
//K = ceil(log(mxn)). mxn - maxm size of the array
// int logg[mxn+1];
// struct RMQ {
//     static const int K = 20;
//     int st[mxn][K + 1];

//     void precalc() {
//         logg[1] = 0;
//         for (int i = 2; i <= mxn; i++)
//         logg[i] = logg[i/2] + 1;
//     }
//     void calc(int N,int * array)  {
//         for (int i = 0; i < N; i++)
//             st[i][0] = array[i];
//         for (int j = 1; j <= K; j++)
//             for (int i = 0; i + (1 << j) <= N; i++)
//                 st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
//     }  
 
//     int query(int L , int R) {
//         int j = logg[R - L + 1];
//         int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
//         return minimum;
//     }
// };

//************************************BIT*************************************
//single point update
//specify 'n' globally
// int n;
// vc<int> bit;
// void update(int idx , int val) {
//     while(idx<=n) {
//         bit[idx]+=val;
//         idx += idx & -idx;
//     }
// }
// int sum (int idx) {
//     int res = 0;
//     while(idx > 0) {
//         res += bit[idx];
//         idx -= idx & -idx;
//     }
//     return res;
// }


// ***************************************DSU**********************************
//initialisation of , parent and size array
//use node as 1 based, not zero based
// vc<int> p ,sz;
// void init(int n) {
//     p.assign(n+3,-1);
//     sz.assign(n+3,1);
// }
// //finding the root of the component
// int root(int x) {
//     if(p[x] == -1) return x;
//     return p[x] = root(p[x]); //path compression
// }   
// //merge two nodes in one component
// void Union(int a , int b) {
//     int par_a = root(a);
//     int par_b = root(b);
//     if(par_a == par_b) return; 
//     if(sz[par_a] < sz[par_b])  
//         swap(a,b);
//     sz[par_a] += sz[par_b];
//     p[par_b] = par_a;
// }
// //check two nodes are in same component
// bool connected(int a ,int b) {
//     return root(a) == root(b);
// }

// ****************************************SIEVE****************************************
//contain all the prime numbers, 1st=-1,2nd = 2 ,3rd = 3, 4th = 5 ....
// vc<int> prime;
// vc<int> sp; //smallest prime divisor of i = sp[i]
// bool isprime[mxn+3]; //checking if a number is prime or not
// void sieve() {
//     prime.clear();
//     sp.assign(mxn+3,-1);
//     for(int i=1; i<=mxn; i++) {
//         sp[i] = i;
//     }
//     sp[2] = 2;
//     prime.pb(-1);
//     memset(isprime,true,sizeof isprime);
//     for(int i=2; i*i<=mxn; ++i)  {
//         if(isprime[i]) {
//             sp[i] = i;
//             for(int j=i*i; j<=mxn; j+=i) {
//                 if(sp[j]==j)
//                     sp[j] = i;
//                 isprime[j] = false;
//             }
//         }
//     }
//     fr(i,2,mxn) {
//         if(isprime[i]){
//             prime.pb(i);
//         }
//     }
// }


//*********************************nCr mod p, p->prime , O(1) per query*****************
// //Define the modulo p int #define statements
// Call the below functions in order, int precomputation phase, before running test cases
// InverseofNumber();
// InverseofFactorial();
// factorial();

// // const int N = mxn;
// // array to store inverse of 1 to N
// int factorialNumInverse[N + 1];
// // array to precompute inverse of 1! to N!
// int naturalNumInverse[N + 1];
// // array to store factorial of first N numbers
// int fact[N + 1];
// // Function to precompute inverse of numbers
// void InverseofNumber()
// {
//     naturalNumInverse[0] = naturalNumInverse[1] = 1;
//     for (int i = 2; i <= N; i++)
//         naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
// }
// // Function to precompute inverse of factorials
// void InverseofFactorial()
// {
//     factorialNumInverse[0] = factorialNumInverse[1] = 1;
//     // precompute inverse of natural numbers
//     for (int i = 2; i <= N; i++)
//         factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
// }
 
// // Function to calculate factorial of 1 to N
// void factorial()
// {
//     fact[0] = 1;
//     // precompute factorials
//     for (int i = 1; i <= N; i++) {
//         fact[i] = (fact[i - 1] * i) % p;
//     }
// }
// // Function to return nCr % p in O(1) time
// int nCr(int N, int R)
// {
//     // n C r = n!*inverse(r!)*inverse((n-r)!)
//     int ans = ((fact[N] * factorialNumInverse[R])
//               % p * factorialNumInverse[N - R])
//              % p;
//     return ans;
// }


void tc() {
    
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; t=1;
    cin>>t;
    while(t--)  tc();
}
