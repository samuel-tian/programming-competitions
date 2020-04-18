/*input
5 7
#######
#F#...#
#.#.#.#
#...#S#
#######
*/
#include <vector>
#include <utility>
#include <iostream>

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
// #define bitSize 262144	/*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;

char maze[100][100];
pii start, finish;
int n, m;
bool pathfound = false;
string solver(int r, int c){
	//cout << "(" << r << ", " << c << ")" << endl;
	if (r == finish.first && c == finish.second){
		pathfound = true;
		return "";
	}
	else{
		int dx[4] = {1, 0, -1, 0};
		int dy[4] = {0, -1, 0, 1};
		string dir[4] = {"R", "U", "L", "D"};
		for (int i = 0; i < 4; i++){
			if (maze[r+dy[i]][c+dx[i]]=='.' || maze[r+dy[i]][c+dx[i]]=='F'){
				string path = dir[i];
				maze[r][c] = '#';
				path += solver(r+dy[i], c+dx[i]);
				if (pathfound == true) return path;
			}
			
		}
		return "";
	}
}
int main(){
	cin >> n >> m;
	string temp[n];
	for (int i = 0; i < n; i++){
		cin >> temp[i];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			maze[i][j] = temp[i][j];
			if (maze[i][j]=='S') start = mp(i, j);
			if (maze[i][j]=='F') finish = mp(i, j);
		}
	}
	cout << solver(start.first, start.second) << endl;;
}