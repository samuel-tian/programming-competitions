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

char board[30][30];
int n;
vii actual;
bool pathfound = false;
void recurse(int r, int c, int count, vii moves){
	if (count == 0){
		for (int i = 0; i < moves.size(); i++){
			actual.pb(moves[i]);
		}
		pathfound = true;
		return;
	}
	int dx[4] = {2, -2, 2, -2};
	int dy[4] = {2, 2, -2, -2};
	int cx[4] = {1, -1, 1, -1};
	int cy[4] = {1, 1, -1, -1};
	for (int i = 0; i < 4; i++){
		int nr = r + dx[i];
		int nc = c + dy[i];
		if (nr >= 0 && nr < n && nc >= 0 && nc < n && board[r+cx[i]][c+cy[i]]=='o' && board[nr][nc] == '+'){
			board[r+cx[i]][c+cy[i]] = '*';
			vii temp;
			for (int i = 0; i < moves.size(); i++)
				temp.pb(mp(moves[i].f, moves[i].s));
			temp.pb(mp(nr, nc));
			recurse(nr, nc, count - 1, temp);
			board[r+cx[i]][c+cy[i]] = 'o';
		}
	}
}
int main(){
	cin >> n;
	string temp[n];
	for (int i = 0; i < n; i++) cin >> temp[i];
	int counter = 0;
	vii kings;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			board[i][j] = temp[i][j];
			if (board[i][j] == 'o') counter++;
			if (board[i][j] == 'K') kings.pb(mp(i, j));
		}
	}
	for (int i = 0; i < kings.size(); i++){
		vii tempe;
		tempe.pb(mp(kings[i].f, kings[i].s));
		recurse(kings[i].f, kings[i].s, counter, tempe);
		if (pathfound == true)
			break;
	}
	if (pathfound == false) cout << "impossible" << endl;
	if (pathfound == true)
		for (int i = 0; i < actual.size(); i++)
			cout << actual[i].f+1 sp actual[i].s+1 << endl;
}