#include <iostream>
#include <algorithm>
#include <set>
#define endl "\n"
#define INF (int)((1LL<<31)-1)
#define MAXN 100000
using namespace std;
typedef pair<int,int> Point;

int n, d, minWidth = INF;
Point raindrops[MAXN];
multiset<int> outside;
int main() {
	//freopen("fpot_cases\\1.in", "r", stdin);
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> raindrops[i].first >> raindrops[i].second;
	}
	sort(raindrops, raindrops + n);

	int left = 0, right = 0;
	outside.insert(raindrops[0].second);
	while (right <= n-1) {
		/*for (multiset<int>::iterator iter = outside.begin(); iter != outside.end(); ++iter) {
			cout << *iter << " ";
		}
		cout << endl;*/
		if (*prev(outside.end()) - *(outside.begin()) >= d) {
			if (minWidth > (raindrops[right].first - raindrops[left].first)) {
				minWidth = (raindrops[right].first - raindrops[left].first);
			}
			multiset<int>::iterator it = outside.find(raindrops[left].second);
			outside.erase(it);
			left++;
		}
		else {
			right++;
			outside.insert(raindrops[right].second);
		}
	}
	if (minWidth == INF) {
		cout << -1 << endl;
		return 0;
	}
	cout << minWidth << endl;
	return 0;
}
