/*input
1000000000000000000
1000000000000000000 1000000000000
*/

#include <iostream>

using namespace std;

#define endl '\n'

int main() {
	long long n, x, y;
	cin >> n >> x >> y;
	long long whitedist = x + y - 2L;
	long long blackdist = 2L * n - x - y;
	cout << (whitedist <= blackdist ? "White" : "Black") << endl;;
}