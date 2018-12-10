/*input
4
3 2 1 3
*/
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define MAXN 100000

int n;
int shuf[MAXN];
vector<int> loop[MAXN];
bool hasPos[MAXN];

int main() {
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> shuf[i];
		--shuf[i];
	}
	
	for (int i = 0; i < n; ++i) {
		//if (hasPos[i]) continue;
		int current = i;
		//loop[i].push_back(current);
		for (int j = 0; j < n+1; ++j) {
			if (hasPos[current]) break;
			if (shuf[current] == i) {
				int next = i;
				for (int k = 0; k < j+1; ++k) {
					hasPos[next] = true;
					next = shuf[next];
				}
				break;
			}
			//loop[i].push_back(current);
			current = shuf[current];
		}
		//loop[i].clear();
	}

	int counter = 0;
	for (int i = 0; i < n; ++i) {
		//cout << hasPos[i] << " ";
		if (hasPos[i]) ++counter;
	}
	cout << counter << endl;
	fclose(stdin);
	fclose(stdout);
}