#include <set>
#include <iostream>
#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pair
#define endl '\n'
#define sp << ' ' <<
using namespace std;
typedef pair<int, int> pii;
const int INF = 2000000000;

set<pii> hayPosition;
set<pii> visited;
int n;
int perimeter;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dx1[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy1[] = {1, 0, -1, 1, -1, 1, 0, -1};

bool farAway(int r, int c) {
	for (int i = 0; i < 8; i++) {
		if (hayPosition.count(mp(r+dx1[i], c+dy1[i]))) {
			return false;
		}
	}
	return true;
}

void floodfill(int r, int c) {
	if (hayPosition.count(mp(r, c))) {
		perimeter++;
		return;
	}
	if (visited.count(mp(r, c))) return;
	visited.insert(mp(r, c));
	if (farAway(r, c)) return;

	for (int i = 0; i < 4; i++) {
		floodfill(r+dx[i], c+dy[i]);
	}
	return;
}

int main() {
	int lowestX = INF;
	int startingY;
	/*freopen("/mnt/c/Users/Samuel/Documents/Programs/USACO/ASTAR/Gold_Basic/Data_Structures_2/Challenge_Problems/perimeter/perimeter_cases/9.out", "r", stdin);
	cin >> startingY; cout << startingY << endl; fclose(stdin);
	freopen("/mnt/c/Users/Samuel/Documents/Programs/USACO/ASTAR/Gold_Basic/Data_Structures_2/Challenge_Problems/perimeter/perimeter_cases/9.in", "r", stdin);*/
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		hayPosition.insert(mp(x, y));
		if (x < lowestX) {
			lowestX = x;
			startingY = y;
		}
	}
	floodfill(lowestX-1, startingY);
	cout << perimeter << endl;

	//fclose(stdin):
	return 0;
}
