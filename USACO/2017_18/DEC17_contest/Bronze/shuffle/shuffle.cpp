/*input
5
1 3 4 5 2
1234567 2222222 3333333 4444444 5555555
*/
#include <iostream>

using namespace std;

#define endl '\n'
#define MAXN 100

int n;
int cowOrder[MAXN];
int shuffle[MAXN], unshuffle[MAXN];
int cowID[MAXN];

int main() {
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cowOrder[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> shuffle[i];
		--shuffle[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> cowID[i];
	}

	for (int i = 0; i < n; ++i) {
		unshuffle[shuffle[i]] = i;
	}
	for (int times = 0; times < 3; ++times) {
		int newCowOrder[MAXN];
		for (int i = 0; i < n; ++i) {
			newCowOrder[i] = cowOrder[shuffle[i]];
		}
		for (int i = 0; i < n; ++i) {
			cowOrder[i] = newCowOrder[i];
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << cowID[cowOrder[i]] << endl;
	}

	fclose(stdin);
	fclose(stdout);
}