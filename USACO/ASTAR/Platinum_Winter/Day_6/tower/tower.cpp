#include <iostream>
#include <climits>
#include <algorithm>
#include <cassert>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 100000

int n;
int balewidth[MAXN];
int dp[MAXN];
// current haybale, number of bales in the row above
int psum[MAXN+1];
// one indexed

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> balewidth[i];
	}
	reverse(balewidth, balewidth + n);
	for (int i = 1; i <= n; ++i) {
		psum[i] = psum[i-1] + balewidth[i-1];
	}
	dp[0] = balewidth[0];
	/* transitions
	compare the running prefix sums and compare to the previous dp state
	1. make new height by adding a new layer and inserting (dp state found before the first partition), add new partition
	2. attach sequence of blocks to existing optimal tower, add new partition
	3. attach block to base of previous tower
	*/
}
