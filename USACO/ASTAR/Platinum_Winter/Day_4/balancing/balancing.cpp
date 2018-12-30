#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <utility>

using namespace std;

#define endl '\n'
#define MAXN 100000
#define INF INT_MAX

int n;
pair<int, int> cows[MAXN];
set<int> xval, yval;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> cows[i].first >> cows[i].second;
		xval.insert(cows[i].first);
		yval.insert(cows[i].second);
	}
}
