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
const int MAXW = 38;
const int MAXH = 100;

int dist[2 * MAXH + 1][2 * MAXW + 1];

int main() {
	int h, w;
	int counter = 0;
	queue<pii> q;
	char maze[2 * MAXH + 1][2 * MAXW + 1];
	string temp[2 * MAXH + 1];
	cin >> w >> h;
	h = 2 * h + 1;
	w = 2 * w + 1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			maze[i][j] = ' ';
		}
	}
	getline(cin, temp[0]);
	for (int i = 0; i < h; i++) {
		getline(cin, temp[i]);
		for (int j = 0; j < temp[i].length(); j++)
			maze[i][j] = temp[i][j];
		for (int j = 0; j < w; j++) {
			if (maze[i][j] == ' ' && (i==0 || i==h-1 || j==0 || j==w-1)) {
				q.push(mp(i, j));
				dist[i][j] = 1;
			}
		}
	}
	while (!q.empty()) {
		pii current = q.front();
		q.pop();
		int dx[4] = {2, 0, -2, 0};
		int dy[4] = {0, 2, 0, -2};
		int dx2[4] = {1, 0, -1, 0};
		int dy2[4] = {0, 1, 0, -1};
		if (counter >= 2) {
			for (int i = 0; i < 4; i++) {
				pii next = mp(current.f + dx[i], current.s + dy[i]);
				pii next2 = mp(current.f + dx2[i], current.s + dy2[i]);
				if (next.f>=0 && next.f<h && next.s>=0 && next.s<w && maze[next2.f][next2.s] == ' ' && maze[next.f][next.s] == ' ') {
					if (dist[next.f][next.s]==0 || dist[next.f][next.s] > dist[current.f][current.s] + 1) {
						dist[next.f][next.s] = dist[current.f][current.s] + 1;
						q.push(next);
					}
				}
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				pii next = mp(current.f + dx2[i], current.s + dy2[i]);
				if (next.f>=0 && next.f<h && next.s>=0 && next.s<w && maze[next.f][next.s] == ' ') {
					if (dist[next.f][next.s]==0 || dist[next.f][next.s] > dist[current.f][current.s] + 1) {
						dist[next.f][next.s] = dist[current.f][current.s] + 1;
						q.push(next);
					}
				}
			}
			counter++;
		}
	}
	int maxdist = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			maxdist = max(maxdist, dist[i][j] - 1);
		}
	}
	cout << maxdist << endl;
	return 0;
}
