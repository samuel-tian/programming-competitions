/*input
10 4
0 0 10 0
10 0 10 10
0 0 0 10
10 10 0 10
8 8 9 8
9 8 8 9
8 9 8 8
2 7 3 2
3 2 7 5
7 5 2 7
15 3
1 4
4 5
7 1
*/
#include <iostream>
#include <algorithm>
#include <climits>
#include <utility>
#include <vector>

using namespace std;

#define endl '\n'
#define MAXN 1000
#define MAXC 1000
#define INF INT_MAX

struct point {
	long long x, y;
	bool operator == (const point& other) {
		return ((this->x == other.x) && (this->y == other.y));
	}
	bool operator != (const point& other) {
		return ((this->x != other.x) || (this->y != other.y));
	}
};
struct line {struct point p1, p2;};

long long ccw(struct point p0, struct point p1, struct point p2) {
	long long dx1 = p1.x - p0.x;
	long long dy1 = p1.y - p0.y;
	long long dx2 = p2.x - p0.x;
	long long dy2 = p2.y - p0.y;
	if (dx1 * dy2 > dy1 * dx2) return 1;
	if (dx1 * dy2 < dy1 * dx2) return -1;
	if ((dx1 * dx2 < 0) || (dy1 * dy2 < 0)) return -1;
	if ((dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2)) return 1;
	return 0;
}

bool intersect(struct line l1, struct line l2) {
	return ((ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2)) <= 0) && ((ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2)) <= 0);
}

int n, c;
struct line fences[MAXN];
struct point cows[MAXC];
int visited[MAXN];
vector<int> communities[MAXN];

bool inside(struct point cow, vector<int> com) {
	int count = 0;
	struct line l1;
	l1.p1 = cow;
	l1.p2 = {INF, cow.y + 1};
	for (int i = 0; i < com.size(); ++i) {
		struct line l2 = fences[com[i]];
		if (intersect(l1, l2)) ++count;
	}
	return count & 1;
}

int findCommunities() {
	int numCommunities = 0;
	for (int i = 0; i < n; ++i) {
		if (visited[i]) continue;
		visited[i] = true;
		point start = fences[i].p1;
		point current = fences[i].p2;
		communities[numCommunities].push_back(i);
		while (current != start) {
			// cout << current.x << " " << current.y << " ";
			for (int j = 0; j < n; ++j) {
				if (visited[j]) continue;
				if (fences[j].p1 == current) {
					current = fences[j].p2;
					communities[numCommunities].push_back(j);
					visited[j] = true;
					break;
				}
				else if (fences[j].p2 == current) {
					current = fences[j].p1;
					communities[numCommunities].push_back(j);
					visited[j] = true;
					break;
				}
			}
			// cout << current.x << " " << current.y << endl;
		}
		++numCommunities;
	}
	return numCommunities;
}

int main() {
	cin >> n >> c;
	for (int i = 0; i < n; ++i) {
		cin >> fences[i].p1.x >> fences[i].p1.y >> fences[i].p2.x >> fences[i].p2.y;
	}
	for (int i = 0; i < c; ++i) {
		cin >> cows[i].x >> cows[i].y;
	}
	int nc = findCommunities();
	/*for (int i = 0; i < nc; ++i) {
		cout << i << ": ";
		for (int j = 0; j < communities[i].size(); ++j) {
			cout << communities[i][j] << " ";
		}
		cout << endl;
	}*/
	bool isIn[c][nc];
	for (int i = 0; i < c; ++i) {
		fill(isIn[i], isIn[i] + nc, false);
	}
	for (int i = 0; i < c; ++i) {
		for (int j = 0; j < nc; ++j) {
			if (inside(cows[i], communities[j])) {
				isIn[i][j] = true;
			}
		}
	}
	/*for (int i = 0; i < c; ++i) {
		for (int j = 0; j < nc; ++j) {
			cout << isIn[i][j] << " ";
		}
		cout << endl;
	}*/
	fill(visited, visited + c, false);
	vector<int> finalCommunities[c];
	for (int i = 0; i < c; ++i) {
		if (visited[i]) continue;
		visited[i] = true;
		finalCommunities[i].push_back(i);
		for (int j = i + 1; j < c; ++j) {
			for (int k = 0; k < nc; ++k) {
				if (isIn[i][k] ^ isIn[j][k]) break;
				if (k == nc - 1) {
					visited[j] = true;
					finalCommunities[i].push_back(j);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < c; ++i) {
		ans = max(ans, (int)finalCommunities[i].size());
	}
	cout << ans << endl;
}