#include <bits/stdc++.h>
#define f first
#define s second
#define t third
#define pb push_back
#define ll long long
#define mp make_pair
#define endl '\n'
#define sp << ' ' <<
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;
const int INF = 2000000000;
const int MAXW = 100;
const int MAXH = 100;

struct triple { int first, second, third; };
int main() {
	int w, h;
	char field[MAXW][MAXH];
	string tempf[MAXW];
	int dist[MAXW][MAXH];
	pii start, end;
	bool firstfound = false;
	//freopen("lphone_cases\\lphone.10.out", "r", stdin); cin >> w; cout << w << endl; fclose(stdin);
	//freopen("lphone_cases\\lphone.10.in", "r", stdin);
	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		cin >> tempf[i];
		for (int j = 0; j < h; j++) {
			dist[i][j] = INF;
			field[i][j] = tempf[i][j];
			if (field[i][j] == 'C' && !firstfound) {
				firstfound = true;
				start = mp(i, j);
			}
			else if (field[i][j] == 'C' && firstfound) end = mp(i, j);
		}
	}
	queue<triple> q;
	q.push({start.f, start.s, -1});
	dist[start.f][start.s] = 0;
	while (!q.empty()) {
		triple current = q.front();
		q.pop();
		if (current.f == end.f && current.s == end.s)
			continue;
		int dx[4] = {0, 1, 0, -1};
		int dy[4] = {1, 0, -1, 0};
		for (int i = 0; i < 4; i++) {
			triple next = {current.f + dx[i], current.s + dy[i], i % 2};
			while (next.f >= 0 && next.f < w && next.s >= 0 && next.s < h && field[next.f][next.s] != '*' && next.t != current.t) {
				if (dist[next.f][next.s] > dist[current.f][current.s] + 1) {
					dist[next.f][next.s] = dist[current.f][current.s] + 1;
					q.push(next);
				}
				next = {next.f + dx[i], next.s + dy[i], next.t};
			}
		}
	}
	cout << dist[end.f][end.s] - 1 << endl;
	//fclose(stdin);
	return 0;
}