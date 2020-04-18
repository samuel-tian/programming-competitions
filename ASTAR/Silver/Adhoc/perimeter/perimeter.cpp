#include <bits/stdc++.h>	//includes everything, supported in CF, usaco, not POJ
#define DEBUG
#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pair
#define endl '\n'
#define sp << ' ' <<
#define inf 2000000000
#define p 1000000007
#define eps 1e-9
#define maxn 100010
#define debug cout << "pass" << endl;
// #define bitSize 262144	/*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;

int bales[102][102];
int floodfill(int r, int c){
	// cout << r sp c << endl;
	int counter = 0;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	for (int i = 0; i < 4; i++){
		int nr = r+dx[i];
		int nc = c+dy[i];
		if (nr >= 0 && nr < 102 && nc >= 0 && nc < 102){
			if (bales[nr][nc] == 1) counter += 1;
			else if (bales[nr][nc] == 0){
				bales[nr][nc] = 2;
				counter += floodfill(nr, nc);
			}
		}
	}
	return counter;
}
int main(){
	int n; cin >> n;
	for (int i = 0; i < n; i++){
		int r, c;
		cin >> c >> r;
		bales[r][c] = 1;
	}
	cout << floodfill(0, 0) << endl;
}