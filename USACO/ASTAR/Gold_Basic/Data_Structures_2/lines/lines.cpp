#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pair
#define endl '\n'
#define sp << ' ' <<
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;
const int INF = 2000000000;
const int MAXN = 200;

pii reduce(pii a) {
	if (a.s == 0) {
		a.f = 0;
		return a;
	}
	if (a.f == 0) {
		a.s = 1;
		return a;
	}
	if (a.s < 0) {
		a.s *= -1;
		a.f *= -1;
	}
	int gcd = 1;
	for (int i = 1; i <= min(abs(a.f), abs(a.s)); i++) {
		if (a.f % i == 0 && a.s % i == 0 && i > gcd) {
			gcd = i;
		}
	}
	a.f /= gcd;
	a.s /= gcd;
	return a;
}

pii points[MAXN];
map<pii, int> distinctSlopes;
int counter = 0;
int main() {
	//freopen("/mnt/c/Users/Samuel/Documents/Programs/USACO/ASTAR/Gold_Basic/Data_Structures_2/lines/lines_cases/lines.6.out", "r", stdin);
	//cin >> counter; cout << counter << endl; fclose(stdin); counter = 0;
	//freopen("/mnt/c/Users/Samuel/Documents/Programs/USACO/ASTAR/Gold_Basic/Data_Structures_2/lines/lines_cases/lines.6.in", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> points[i].f >> points[i].s;
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			pii slope;
			slope.f = points[i].f - points[j].f;
			slope.s = points[i].s - points[j].s;
			slope = reduce(slope);
			if (distinctSlopes[slope] == 0) {
				//cout << slope.f << " / " << slope.s << endl;
				counter++;
				distinctSlopes[slope] = 1;
			}
		}
	}
	cout << counter << endl;

	//fclose(stdin);
	return 0;
}
