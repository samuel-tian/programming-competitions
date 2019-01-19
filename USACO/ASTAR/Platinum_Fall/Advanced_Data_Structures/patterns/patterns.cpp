#include <iostream>
#include <climits>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 20000

struct Node {
	Node* children[26];
	Node* parent;

}

int n, k;
int milkproduction[MAXN];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> milkproduction[i];
	}

}
