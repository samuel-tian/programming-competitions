/*input
4 16
*/

#include <iostream>

using namespace std;

#define endl '\n'
#define INF (int)((1LL<<31)-1)
#define MAXN 10

int n, finalSum;
int startingNums[MAXN];
bool numUsed[MAXN];
bool solFound = false;

int factorial(int x) {
	int ret = 1;
	for (int i = 1; i <= x; ++i) {
		ret *= i;
	}
	return ret;
}
int choose(int a, int b) {
	// a choose b
	return (factorial(a-1) / (factorial(b) * factorial(a-1-b)));
}

bool sumEquals() {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += choose(n, i) * startingNums[i];
	}
	//cout << sum << endl;
	return (sum == finalSum);
}

void genNums(int depth) {
	
	if (solFound) return;
	if (depth == n) {
		/*for (int i = 0; i < n; ++i) {
			cout << startingNums[i] << " ";
		}*/
		if (sumEquals()) {
			for (int i = 0; i < n; ++i) {
				if (i == 0) {
					cout << startingNums[i];
				}
				else {
					cout << " " << startingNums[i];
				}
			}
			cout << endl;
			solFound = true;
			return;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!numUsed[i-1]) {
			startingNums[depth] = i;
			numUsed[i-1] = true;
			genNums(depth + 1);
			numUsed[i-1] = false;
		}

	}
}

int main() {
	cin >> n >> finalSum;
	genNums(0);
}