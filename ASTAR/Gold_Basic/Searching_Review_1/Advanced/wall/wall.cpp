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
const int MAXF = 10000;

int dist[MAXF];

ll distance (pii a, pii b) {
	ll xdif = (a.f - b.f) * (a.f - b.f);
	ll ydif = (a.s - b.s) * (a.s - b.s);
	return (ll) ceil(sqrt(xdif + ydif));
}

int main() {
	int h, f;
	int mindist = INF;
	pii points[MAXF];
	vector<int> adjacent[MAXF];
	queue<int> q;
	//freopen("wall_cases\\wall.10.out", "r", stdin); cin >> h; cout << "ans" sp h << endl; fclose(stdin);
	//freopen("wall_cases\\wall.10.in", "r", stdin);
	cin >> h >> f;
	for (int i = 0; i < f; i++) {
		cin >> points[i].f >> points[i].s;
		if (points[i].s <= 1000) {
			q.push(i);
			dist[i] = 1;
		}
	}
	for (int i = 0; i < f - 1; i++) {
		for (int j = i + 1; j < f; j++) {
			if (distance(points[i], points[j]) <= 1000) {
				adjacent[i].pb(j);
				adjacent[j].pb(i);
			}
		}
	}

	/*for (int i = 0; i < f; i++) {
		cout << i << ": ";
		for (int j = 0; j < adjacent[i].size(); j++) {
			cout << adjacent[i][j] << " ";
		}
		cout << endl;
	}*/

	while (!q.empty()) {
		int current = q.front();
		pii cpoint = points[q.front()];
		q.pop();
		if (cpoint.s >= h - 1000) {
			if (dist[current] < mindist)
				mindist = dist[current];
			continue;
		}
		for (int i = 0; i < adjacent[current].size(); i++) {
			int next = adjacent[current][i];
			if (dist[next] == 0 || dist[next] > dist[current] + 1) {
				dist[next] = dist[current] + 1;
				q.push(next);
			}
		}
	}
	cout << mindist << endl;

	//fclose(stdin);
	return 0;
}