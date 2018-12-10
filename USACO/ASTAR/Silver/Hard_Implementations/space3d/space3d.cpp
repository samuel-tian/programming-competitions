/*input

*/
#include <bits/stdc++.h>
#define DEBUG
#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pair
#define mt make_tuple
#define endl '\n'
#define sp << ' ' <<
#define inf 2000000000
#define p 1000000007
#define eps 1e-9
#define MAXN 100010
#define debug cout << "pass" << endl;
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;

struct triple{ int x, y, z; };

char space[100][100][100];
int n;
void floodfill(int x, int y, int z){
	int dx[6] = {1, -1, 0, 0, 0, 0};
	int dy[6] = {0, 0, 1, -1, 0, 0};
	int dz[6] = {0, 0, 0, 0, 1, -1};
	queue<triple> q;
	q.push((triple) {x, y, z});
	while (!q.empty()){
		triple current = q.front(); q.pop();
		for (int i = 0; i < 6; i++){
			int nextx = current.x+dx[i];
			int nexty = current.y+dy[i];
			int nextz = current.z+dz[i];
			triple next = {nextx, nexty, nextz};
			if (nextx>=0 && nextx<n && nexty>=0 && nexty<n && nextz>=0 && nextz<n && space[nextx][nexty][nextz] == '*'){
				q.push(next);
				space[nextx][nexty][nextz] = '.';
			}
		}
	}
}
int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			string temp; cin >> temp;
			for (int k = 0; k < n; k++){
				space[i][j][k] = temp[k];
			}
		}
	}
	int counter = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				if (space[i][j][k] == '*'){
					space[i][j][k] = '.';
					floodfill(i, j, k);
					counter++;
				}
			}
		}
	}
	cout << counter << endl;
}