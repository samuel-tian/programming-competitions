#include <iostream>
#include <queue>
using namespace std;
#define f first
#define s second
const int INF = (int) ((1LL<<31)-1);
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int shift = 500;

int dist[1001][1001];
bool mudPuddle[1001][1001];
int bessieX, bessieY, n;

int main() {
	int puddleX, puddleY;
	cin >> bessieX >> bessieY >> n;
	bessieX += shift;
	bessieY += shift;
	for (int i = 0; i < n; i++) {
		cin >> puddleX >> puddleY;
		mudPuddle[puddleX+shift][puddleY+shift] = true;
	}
	dist[shift][shift] = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(shift, shift));
	while (!q.empty()) {
		pair<int, int> current = q.front();
		q.pop();
		if (current.f == bessieX && current.s == bessieY) {
			continue;
		}
		for (int i = 0; i < 4; i++) {
			pair<int, int> next = make_pair(current.f + dx[i], current.s + dy[i]);
			if (next.f>=0 && next.f<1001 && next.s>=0 && next.s<1001 && !mudPuddle[next.f][next.s]) {
				if (dist[next.f][next.s] == 0 || dist[next.f][next.s] > dist[current.f][current.s] + 1) {
					dist[next.f][next.s] = dist[current.f][current.s] + 1;
					q.push(next);
				}
			}

		}
	}
	cout << dist[bessieX][bessieY]-1 << endl;
}
