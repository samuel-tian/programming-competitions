/*input
1 2 3 5
6 0 10 4
2 1 8 3
*/

#include <iostream>

using namespace std;

#define endl '\n'

int main() {
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
	double a1x, a1y, a2x, a2y;
	double b1x, b1y, b2x, b2y;
	double c1x, c1y, c2x, c2y;
	cin >> a1x >> a1y >> a2x >> a2y;
	cin >> b1x >> b1y >> b2x >> b2y;
	cin >> c1x >> c1y >> c2x >> c2y;
	a1x -= 0.5; a2x -= 0.5; a1y -= 0.5; a2y -= 0.5;
	b1x -= 0.5; b2x -= 0.5; b1y -= 0.5; b2y -= 0.5;
	c1x -= 0.5; c2x -= 0.5; c1y -= 0.5; c2y -= 0.5;
	int counter = 0;
	for (int i = -1001; i <= 1000; ++i) {
		for (int j = -1001; j <= 1000; ++j) {
			if (i >= c1x && i <= c2x && j >= c1y && j <= c2y) continue;
			else if (i >= a1x && i <= a2x && j >= a1y && j <= a2y) ++counter;
			else if (i >= b1x && i <= b2x && j >= b1y && j <= b2y) ++counter;
		}
	}
	cout << counter << endl;

	fclose(stdin);
	fclose(stdout);
}