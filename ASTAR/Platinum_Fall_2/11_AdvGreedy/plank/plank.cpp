#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'

const int MAXN = 20000;
const int INF = INT_MAX;

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int n;

int main() {
	cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		pq.push(-1 * a);
	}
	long long ret = 0;
	while (pq.size() > 1) {
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		ret += -1 * (first + second);
		pq.push(first + second);
	}
	cout << ret << endl;
}