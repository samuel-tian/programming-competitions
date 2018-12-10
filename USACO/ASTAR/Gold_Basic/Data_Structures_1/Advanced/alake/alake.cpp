#include <iostream>
using namespace std;
const int INF = ((1LL<<31)-1);
const int MAXN = 100000;

int start=0, n;
int width[MAXN+2], height[MAXN+2];
int lleft[MAXN+2], rright[MAXN+2];
bool visited[MAXN+2];
long long totalTime, ans[MAXN+2];

int nextLower(int cur, int dir) {
	while ((visited[cur] || (height[cur+dir]<height[cur] && !visited[cur+dir])) && cur+dir>=0 && cur+dir<= n+1) {
		cur += dir;
	}
	return cur;
}

int main() {
	//freopen("/mnt/c/Users/Samuel/Documents/Programs/USACO/ASTAR/Gold_Basic/Data_Structures_1/Advanced/alake/alake_cases/alake.5.in", "r", stdin);
	cin >> n;
	height[0] = INF;
	height[n+1] = INF;
	for (int i = 1; i <= n; i++) {
		lleft[i] = i-1; rright[i] = i+1;
		cin >> width[i] >> height[i];
		if (height[start] > height[i]) {
			start = i;
		}
	}

	while (start != 0 && start != n+1) {
		ans[start] = totalTime + width[start];
		visited[start] = true;
		lleft[rright[start]] = lleft[start];
		rright[lleft[start]] = rright[start];
		int dir, next;
		int lnext = lleft[start]; int rnext = rright[start];
		if (height[rnext] < height[lnext]) {
			dir = 1;
			next = rnext;
		}
		else {
			dir = -1;
			next = lnext;
		}
		totalTime += ((long long) (width[start]) * (height[next] - height[start]));
		width[next] += width[start];
		start = nextLower(next, dir);

	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}

	//fclose(stdin);
	return 0;
}
