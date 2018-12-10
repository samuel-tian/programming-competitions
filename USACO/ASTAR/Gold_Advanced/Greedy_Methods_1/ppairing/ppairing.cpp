/*input
8 3
2
2
4
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

#define endl '\n'

int main() {
	int n, c;
	scanf("%d%d", &n, &c);
	priority_queue<pair<int, int> > pearls;
	// first is number of pearls left
	// second is color of pearl

	for (int i = 1; i <= c; ++i) {
		int a;
		scanf("%d", &a);
		pearls.push(make_pair(a, i));
	}
	while (!pearls.empty()) {
		pair<int, int> a, b;
		a = pearls.top();
		pearls.pop();
		if (pearls.top().first == 0) break;
		printf("%d %d\n", a.second, pearls.top().second);
		--a.first;
		--pearls.top().second;
		pearls.push(a);
	}

	return 0;
}