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
const int MAXN = 100000;

int n;
int parens[MAXN];
ll nested[MAXN / 2];

int main() {
	freopen("/mnt/c/Users/Samuel/Documents/Programs/USACO/ASTAR/Gold_Basic/Data_Structures_1/paren/paren_cases/paren.8.out", "r", stdin);
	cin >> n; cout << "ans" sp n << endl; fclose(stdin);
	freopen("/mnt/c/Users/Samuel/Documents/Programs/USACO/ASTAR/Gold_Basic/Data_Structures_1/paren/paren_cases/paren.8.in", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> parens[i];
		// if (i == 0) parens[i] = 1;
		// else parens[i] = parens[i-1] + (-2 * parens[i] + 1);
	}
	int nestLevel = 0;
	for (int i = 0; i < n; i++) {
		if (parens[i] == 0 && parens[i + 1] == 1) {
			nested[nestLevel]++;
			i++;
		}
		else if (parens[i] == 0) {
			nestLevel++;
		}
		else {
			nested[nestLevel - 1] = (nested[nestLevel - 1] + (2 * nested[nestLevel])) % 12345678910;
			nested[nestLevel] = 0;
			nestLevel--;
		}
	}
	cout << nested[0] << endl;

	fclose(stdin);
	return 0;
}
