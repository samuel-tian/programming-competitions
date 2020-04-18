#include <iostream>
#include <climits>
#include <algorithm>
#include <utility>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 300

int m, p;
pair<int, int> problems[MAXN];

int main() {
	cin >> m >> p;
	for (int i = 0; i < p; ++i) {
		cin >> problems[i].first >> problems[i].second;
	}
}
