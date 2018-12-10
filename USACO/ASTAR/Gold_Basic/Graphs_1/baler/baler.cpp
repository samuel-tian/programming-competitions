#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define endl "\n"
#define sp << " " <<
const int INF = 2147483647;
const int MAXN = 1050;

struct baler {
	int x;
	int y;
	int r;
};
int n, endf;
vector<int> adjacent[MAXN];
bool visited[MAXN];
baler points[MAXN];

int dist(baler a, baler b) {
	return ((int)pow(a.x-b.x, 2) + (int)pow(a.y-b.y, 2));
}

double recurse(int cur, double sum, double rot) {
	//cout << cur sp sum << endl;
	if (cur == endf) {
		return sum;
	}
	for (int i = 0; i < adjacent[cur].size(); i++) {
		int next = adjacent[cur][i];
		double rotations = (rot*points[cur].r)/(points[next].r);
		if (visited[next]) {
			continue;
		}
		visited[next] = true;
		int finish = recurse(next, sum+rotations, rotations);
		if (finish != -1) {
			//cout << "cur" sp cur sp "- next" sp next sp "= sum" sp rotations << endl;
			return finish;
		}
		visited[next] = false;
	}
	return -1;
}

int main() {
	//freopen("/mnt/c/Users/Samuel/Documents/Programs/USACO/ASTAR/Gold_Basic/Graphs_1/baler/baler_cases/baler.1.in", "r", stdin);
	/*freopen("baler_cases\\baler.10.out", "r", stdin);
	cin >> n; cout << n << endl; fclose(stdin);
	freopen("baler_cases\\baler.10.in", "r", stdin);*/
	int endfx, endfy, start;
	cin >> n >> endfx >> endfy;
	for (int i = 0; i < n; i++) {
		cin >> points[i].x >> points[i].y >> points[i].r;
		if (points[i].x == endfx && points[i].y == endfy) {
			endf = i;
		}
		else if (points[i].x == 0 && points[i].y == 0) {
			start = i;
		}
	}
	//cout << n sp endfx sp endfy sp endf << endl;
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (dist(points[i], points[j]) == (int)pow(points[i].r + points[j].r, 2)) {
				adjacent[i].push_back(j);
				adjacent[j].push_back(i);
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		cout << i sp ":" sp points[i].x sp points[i].y sp points[i].r << endl;
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (int j = 0; j < adjacent[i].size(); j++) {
			cout << adjacent[i][j] << " ";
		}
		if (i == endf) {
			cout << "<- end";
		}
		else if (i == start) {
			cout << "<- start";
		}
		cout << endl;
	}
	cout << endl;*/

	visited[start] = true;
	cout << (int)recurse(start, 10000.0, 10000.0) << endl;

	//fclose(stdin);
	return 0;
}
