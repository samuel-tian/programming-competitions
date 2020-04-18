#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pair
#define endl '\n'
#define sp << ' ' <<
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;
const int INF = 2000000000;

int m;
int nums[30];
void recurse(int pos, int current, int power) {
	if (pos == -1){
		if (current == 0) return;
		cout << current << endl;
	}
	else {
		recurse(pos - 1, current, power);
		recurse(pos - 1, current + pow(10, power) * nums[pos], power + 1);
	}
	return;
}
int main() {
	cin >> m;
	for (int i = 0; i < m; i++) cin >> nums[i];
	recurse(m-1, 0, 0);
	return 0;
}
