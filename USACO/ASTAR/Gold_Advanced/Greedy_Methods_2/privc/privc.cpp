/*input
9
2
2
1
3
3
3
2
3
1
*/

#include <iostream>

using namespace std;

#define endl '\n'
#define MAXN 1000

int main() {
	int n;
	int ans = 0;
	int count[3] = {0, 0, 0};
	int position[MAXN];
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> position[i];
		++count[position[i] - 1];
	}
	int start[3] = {0, count[0], count[0] + count[1]};
	int finish[3] = {start[1], start[2], n};
	/* ideal and nonideal switches for 1 */
	for (int i = start[0]; i < finish[0]; ++i) {
		if (position[i] != 1) {
			int num = position[i] - 1;
			for (int j = start[num]; j < finish[num]; ++j) {
				if (position[j] == 1) {
					position[j] = num + 1;
					position[i] = 1;
					++ans;
					break;
				}
			}
			if (position[i] != 1) {
				num = 3 - num;
				for (int j = start[num]; j < finish[num]; ++j) {
					if (position[j] == 1) {
						position[j] = position[i];
						position[i] = 1;
						++ans;
						break;
					}
				}
			}
		}
	}
	/* switches for 2 */
	for (int i = start[1]; i < finish[1]; ++i) {
		if (position[i] == 3) {
			for (int j = start[2]; j < finish[2]; ++j) {
				if (position[j] == 2) {
					position[j] = 3;
					position[i] = 2;
					++ans;
					break;
				}
			}
		}
	}
	cout << ans << endl;
}

/*
for (int i = 0; i < n; ++i) {
	cout << position[i] << " ";
} cout << endl;
*/