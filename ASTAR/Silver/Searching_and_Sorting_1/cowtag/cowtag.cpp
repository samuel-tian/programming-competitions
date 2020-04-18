#include <bits/stdc++.h>	//includes everything, supported in CF, usaco, not POJ
#define DEBUG
#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pair
#define endl '\n'
#define sp << ' ' <<
#define inf 9223372036854775807
#define p 1000000007
#define eps 1e-9
#define maxn 100010
#define debug cout << "pass" << endl;
// #define bitSize 262144	/*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;
 
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
ll dist[1000][1000];
int main(){
	int n; cin >> n;
	bool dead[n]; for (int i = 0; i < n; i++) dead[i] = false;
	pii coor[n]; for (int i = 0; i < n; i++) cin >> coor[i].f >> coor[i].s;
	
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			int x = coor[i].f-coor[j].f;
			int y = coor[i].s-coor[j].s;
			dist[i][j] = x*x + y*y;
			dist[j][i] = dist[i][j];
		}
	}
	int current = 0;
	for (int turn = 0; turn < n-1; turn++){
		
		ll smalldist = inf;
		int closest;
		for (int cow = 0; cow < n; cow++){
			// cout << cow sp dead[cow]==0 sp current!=cow sp dist[current][cow]<smalldist << endl;
			// bool boolean = (dist[current][cow] < smalldist);
			// cout << boolean << endl;
			if (!dead[cow] && cow!=current && dist[current][cow] < smalldist){
				// debug;
				closest = cow;
				smalldist = dist[current][cow];
			}
		}
		// cout << closest << endl;
		dead[closest] = true;
		current = (current+1)%n;
		while (dead[current]==true)
			current = (current+1)%n;
	}
	cout << current + 1 << endl;
}