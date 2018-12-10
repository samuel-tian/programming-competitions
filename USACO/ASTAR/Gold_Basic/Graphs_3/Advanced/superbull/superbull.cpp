#include <iostream>

using namespace std;

#define INF (int)((1LL<<31)-1)
#define endl '\n'
#define MAXN 2000

int n;
int id[MAXN], points[MAXN];
int pointsScored[MAXN][MAXN];
bool visited[MAXN];

int maxGame() {
	int ret, maxPoints = -1;
	for (int i = 0; i < n; ++i) {
		if (points[i] > maxPoints && !visited[i]) {
			maxPoints = points[i];
			ret = i;
		}
	}
	return ret;
}

long long mst() {
	for (int times = 0; times < n-1; ++times) {
		int next = maxGame();
		//cout << "next: " << next << endl;
		visited[next] = true;
		for (int i = 0; i < n; ++i) {
			if (i == next) continue;
			if (pointsScored[next][i] > points[i] && !visited[i]) {
				points[i] = pointsScored[next][i];
			}
		}
	}

	long long ret = 0;
	for (int i = 0; i < n; ++i) {
		//cout << points[i] << " ";
		ret += points[i];
	}
	//cout << endl;
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> id[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			pointsScored[i][j] = id[i] ^ id[j];
			//cout << pointsScored[i][j] << " ";
		}
		//cout << endl;
	}
	cout << mst() << endl;
}
