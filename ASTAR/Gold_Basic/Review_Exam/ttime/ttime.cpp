#include <iostream>
#include <vector>
using namespace std;
const int INF = ((1LL<<31)-1);
const int MAXN = 1000;
const int MAXM = 2000;
const int MAXQ = 100;

int n, m, q;
vector<int> adjacent[MAXN];
pair<int, int> query[MAXQ];
int graphNum[MAXN];
void search(int start, int num) {
	graphNum[start] = num;
	for (int i = 0; i < adjacent[start].size(); i++) {
		if (graphNum[adjacent[start][i]] == 0) {
			search(adjacent[start][i], num);
		}
	}
}
int main() {
	cin >> n >> m >> q;
	int f, s;
	for (int i = 0; i < m; i++) {
		cin >> f >> s;
		adjacent[f].push_back(s);
		adjacent[s].push_back(f);
	}
	for (int i = 0; i < q; i++) {
		cin >> query[i].first >> query[i].second;
	}
	int label = 1;
	for (int i = 0; i < n; i++) {
		if (graphNum[i] == 0) {
			search(i, label);
			label++;
		}
	}

	for (int i = 0; i < q; i++) {
		int f = query[i].first; int s = query[i].second;
		if (graphNum[f] == graphNum[s]) {
			cout << "Y" << endl;
		}
		else {
			cout << "N" << endl;
		}
	}

	return 0;
}
