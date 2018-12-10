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
const int MAXN = 500;
const int MAXM = 500;

int n, m;
char grid[MAXN][MAXM];
int dist[MAXN][MAXM];
pii start, finish;
bool possibleFlip(int r, int c, bool flipped) {
	if (flipped) {
		while (grid[r+1][c] != '#' && r+1 < n) {
			
			r++;
			if (grid[r+1][c] == 'D') return true;
		}
		if (r == n-1) return false;
		return true;
	}
	else if (!flipped) {
		while (grid[r-1][c] != '#' && r-1 >= 0){
			
			r--;
			if (grid[r-1][c] == 'D') return true;
		}
		if (r == 0) return false;
		return true;
	}
}

pii flipGravity(int r, int c, bool flipped) {
	if (flipped) {
		while (grid[r+1][c] != '#' && r+1 < n) {
			
			r++;
			if (grid[r][c] == 'D') return finish;
		}
	}

	else if (!flipped) {
		while (grid[r-1][c] != '#' && r-1 >= 0) {
			
			r--;
			if (grid[r][c] == 'D') return finish;
		}
	}

	return mp(r, c);
}

bool possibleFall(int r, int c, bool flipped) {
	if (flipped) {
		while (grid[r-1][c] != '#' && r-1 >= 0){
			
			r--;
			if (grid[r][c] == 'D') return true;
		}
		if (r == 0) return false;
		return true;
	}
	else if (!flipped) {
		while (grid[r+1][c] != '#' && r+1 < n){
			
			r++;
			if (grid[r][c] == 'D') return true;
		}
		if (r == n-1) return false;
		return true;
	}
}

pii fall(int r, int c, bool flipped) {
	if (flipped) {
		while (grid[r-1][c] != '#' && r-1 >= 0) {
			
			r--;
			if (grid[r][c] == 'D') return finish;
		}
	}
	else if (!flipped) {
		while (grid[r+1][c] != '#' && r+1 < n) {
			
			r++;
			if (grid[r][c] == 'D') return finish;
		}
	}
	return mp(r, c);
}

struct triple { int first, second, third; };

int main() {
	string temp[MAXN];
	freopen("gravity_cases\\9.out", "r", stdin); cin >> n; cout << n << endl; fclose(stdin);
	freopen("gravity_cases\\9.in", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp[i];
		for (int j = 0; j < m; j++) {
			dist[i][j] = INF;
			grid[i][j] = temp[i][j];
			//cout << grid[i][j] << " ";
			if (grid[i][j] == 'C') start = mp(i, j);
			else if (grid[i][j] == 'D') finish = mp(i, j);
		}
		//cout << endl;
	}
	queue<triple> q;
	if (possibleFall(start.f, start.s, false)) start = fall(start.f, start.s, false);
	else goto HERE;
	q.push({start.f, start.s, false});
	dist[start.f][start.s] = 0;
	while (!q.empty()) {
		pii current = mp(q.front().f, q.front().s);
		bool flipped = q.front().t;
		//cout << current.f sp current.s << endl;
		q.pop();
		if (current == finish) continue;
		int d[2] = {1, -1};
		for (int i = 0; i < 2; i++) {
			pii next = mp(current.f, current.s + d[i]);
			if (next.f >= 0 && next.f < n && grid[next.f][next.s] != '#' && possibleFall(next.f, next.s, flipped)){
				next = fall(next.f, next.s, flipped);
				if (dist[current.f][current.s] < dist[next.f][next.s]) {
					dist[next.f][next.s] = dist[current.f][current.s];
					q.push({next.f, next.s, flipped});
					// cout << current.f sp current.s sp "->" sp next.f sp next.s << endl;
				}
			}
		}
		if (possibleFlip(current.f, current.s, flipped)) {
			pii next = flipGravity(current.f, current.s, flipped);
			// cout << "gravity next" sp next.f sp next.s << endl;
			if (dist[next.f][next.s] > dist[current.f][current.s] + 1) {
				dist[next.f][next.s] = dist[current.f][current.s] + 1;
				q.push({next.f, next.s, !flipped});
			}
		}
	}
	HERE:
	if (dist[finish.f][finish.s] == INF) cout << -1 << endl;
	else cout << dist[finish.f][finish.s] << endl;

	fclose(stdin);
	return 0;
}