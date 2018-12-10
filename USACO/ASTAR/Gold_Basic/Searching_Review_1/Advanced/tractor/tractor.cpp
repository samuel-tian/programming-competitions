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
const int MAX = 1001;

bool field[MAX][MAX];
int dist[MAX][MAX];
int main() {
	int n;
	pii start; pii temp;
	//freopen("tractor_cases\\10.out", "r", stdin); cin >> n; cout << n << endl; fclose(stdin);
	//freopen("tractor_cases\\10.in", "r", stdin);
	cin >> n; cin >> start.f >> start.s;
	for (int i = 0; i < n; i++) {
		cin >> temp.f >> temp.s;
		field[temp.f][temp.s] = true;
	}
	queue<pii> q0, q1;
	q0.push(start);
	dist[start.f][start.s] = 1;
	while (!q0.empty() || !q1.empty()) {
		if (q0.empty()) {
			while (!q1.empty()) {
				q0.push(q1.front());
				q1.pop();
			}
			continue;
		}
		pii current = q0.front();
		q0.pop();
		if (current.f == 0 || current.f == MAX-1 || current.s == 0 || current.s == MAX-1) continue;
		int dx[4] = {1, 0, -1, 0};
		int dy[4] = {0, 1, 0, -1};
		for (int i = 0; i < 4; i++) {
			pii next = mp(current.f + dx[i], current.s + dy[i]);
			if (next.f>=0 && next.f<MAX && next.s>=0 && next.s<MAX) {
				if (field[next.f][next.s]) {
					if (dist[next.f][next.s] > dist[current.f][current.s] + 1 || dist[next.f][next.s] == 0){
						dist[next.f][next.s] = dist[current.f][current.s] + 1;
						q1.push(next);
					}
				}
				else {
					if (dist[next.f][next.s] > dist[current.f][current.s] || dist[next.f][next.s] == 0) {
						dist[next.f][next.s] = dist[current.f][current.s];
						q0.push(next);
					}
				}
			}
		}
	}
	int mindist = INF;
	for (int i = 1; i < MAX-1; i++) {
		mindist = min(mindist, dist[i][0]);
		mindist = min(mindist, dist[i][MAX-1]);
		mindist = min(mindist, dist[0][i]);
		mindist = min(mindist, dist[MAX-1][i]);
	}
	cout << mindist - 1 << endl;
	//fclose(stdin);
	return 0;
}