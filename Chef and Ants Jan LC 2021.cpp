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
#define fr(i, a, n) for (int i = a; i <= n; i++)
#define frr(i, a, n) for (int i = n - 1; i >= a; i--)
#define file_in freopen("a.txt", "r", stdin);
const int mxn=1e6;

void tc() {
	int n; cin>>n;
	//d[distance from O] = ant_no
	map<int,vc<int>> d;
	int ant_no = 1;
	vc<pair<int,pair<int,int>>> v;
	vc<pair<int,int>> line(n+2);

	fr(line_no,1,n) {
		int positves = 0 , negatives = 0;
		//m ants on line i
		int m; cin>>m;
		fr(j,1,m) {
			int dist; cin>>dist;
			d[abs(dist)].pb(ant_no);
			int side = -1;
			if(dist > 0) side = 1;
			v.pb({ant_no,{line_no,side}});
			ant_no++;
			if(side>0) positves++;
			else negatives++;
		}
		line[line_no] = {positves,negatives};
	}

	//for each ant, save the line no, and the side
	vc<pair<int,int>> ant(ant_no+1);
	int i = 1;
	for(auto el : v) {
		ant_no = el.first;
		int line_no = el.second.first;
		int side = el.second.second;
		ant[ant_no] = {line_no,side};
	}

	int ans = 0;
	//count all the collisions occuring at point O

	for(auto el : d) {
		int dist = el.first;
		//if there is only one ant at this distance from O, 
		// then there will be no collision at O
		if(d[dist].size() <= 1) {
			int antno = d[dist].front();
			int line_no = ant[antno].first;
			int side = ant[antno].second;
			if(side > 0) {
				ans += line[line_no].second;
				line[line_no].first--;
			} else{
				ans += line[line_no].first;
				line[line_no].second--;
			}
			continue;
		}

		//calculating collisions at O
		for(int antno : d[dist]) {
			int line_no = ant[antno].first;
			int side = ant[antno].second;
			if(side > 0) {
				ans += 1*(line[line_no].first-1);
				//remove the ant
				line[line_no].first--;
			} else {
				ans += 1*(line[line_no].second -1);
				//remove the ant
				line[line_no].second--;
			}
		}
		//1 for collision at O 
		ans++;
	}

	//the remaining ants, do not collide at point O, 
	// but will collide at other points on the same line
	for(int line_no = 1; line_no<=n; line_no++) {
		ans += (line[line_no].first * line[line_no].second);
	}
	cout<<ans<<"\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; t=1;
    cin>>t;
    while(t--)  tc();
}
