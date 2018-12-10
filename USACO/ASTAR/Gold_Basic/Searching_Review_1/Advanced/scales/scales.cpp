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
const int MAXN = 1000;

int n, c, maxWeight = 0;
int masses[MAXN];

void recurse(int counter, int weight) {
	// cout << counter sp weight << endl;
	if (counter == -1) {
		maxWeight = max(maxWeight, weight);
		return;
	}
	else if (counter == 0){
		if (weight + masses[counter] > c) recurse(-1, weight);
		else recurse(-1, weight + masses[counter]);
	}
	else{
		if (masses[counter] > c - weight) recurse(counter-1, weight);
		else if (masses[counter] + masses[counter-1] <= c - weight) recurse(counter - 2, weight + masses[counter] + masses[counter-1]);
		else {
			recurse(counter - 2, weight + masses[counter]);
			recurse(counter - 2, weight + masses[counter-1]);
		}
	}
	return;
}

void badRecurse(int counter, int weight) {
	if (counter == n) {
		maxWeight = max(maxWeight, weight);
		return;
	}
	if (weight + masses[counter] <= c) badRecurse(counter + 1, weight + masses[counter]);
	badRecurse(counter + 1, weight);
}

int main() {
	// freopen("scales_cases\\4.out", "r", stdin); cin >> n; cout << n << endl; fclose(stdin);
	// freopen("scales_cases\\4.in", "r", stdin);
	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> masses[i];
	if (n > 20) recurse(n-1, 0);
	else badRecurse(0, 0);
	cout << maxWeight << endl;

	// fclose(stdin);
	return 0;
}