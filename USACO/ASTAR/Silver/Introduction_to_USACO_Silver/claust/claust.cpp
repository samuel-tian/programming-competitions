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
// #define bitSize 262144	/*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;

ll square(ll x){
	return x*x;
}

int main(){
	int n; cin >> n;
	pii cows[n];
	for (int i = 0; i < n; i++) cin >> cows[i].f >> cows[i].s;
	pair<pii, ll> mindist = mp(mp(0, 0), inf);
	for (int i = 0; i < n-1; i++){
		for (int j = i+1; j < n; j++){
			ll xdif = cows[i].f - cows[j].f;
			ll ydif = cows[i].s - cows[j].s;
			ll dist = square(xdif) + square(ydif);
			if (dist < mindist.s){
				// cout << xdif sp square(xdif) sp ydif sp square(ydif) << endl;
				mindist = mp(mp(i+1, j+1), dist);
				// cout << mindist.f.f sp mindist.f.s sp mindist.s << endl;
			}
		}
	}
	cout << mindist.f.f sp mindist.f.s << endl;
}