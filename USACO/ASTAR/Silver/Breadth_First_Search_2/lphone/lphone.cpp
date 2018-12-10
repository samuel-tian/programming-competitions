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
#define print cout << "pass" << endl;
// #define bitSize 262144	/*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<pii> vii;

int main(){														 // USACO
	int rows, cols; cin >> cols >> rows;
	char field[rows][cols];
	string temp[rows];
	int mirror[rows][cols];
	for (int i = 0; i < rows; i++) cin >> temp[i];
	pii start, end;
	bool firstcow = true;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			mirror[i][j] = inf;
			field[i][j] = temp[i][j];
			// cout << field[i][j];
			if (field[i][j]=='C' && firstcow==true){
				start = mp(i, j);
				firstcow = false;
			}
			else if (field[i][j]=='C' && firstcow==false) end = mp(i, j);
		}
		// cout << endl;
	}
	// cout << "(" << start.f << ", " << start.s << ")" sp "(" << end.f << ", " << end.s << ")" << endl;
	
	mirror[start.f][start.s] = 0;
	queue<piii> q;
	q.push(mp(start, 2));
	while (!q.empty()){
		piii current = q.front();
		q.pop();
		if (current.f == end) continue;
		int dx[4] = {1, 0, -1, 0};
		int dy[4] = {0, 1, 0, -1};
		int dir[4] = {1, 0, 1, 0};
		for (int i = 0; i < 4; i++){
			piii next = mp(mp(current.f.f+dx[i], current.f.s+dy[i]), dir[i]);
			while (next.f.f>=0 && next.f.f<rows && next.f.s>=0 && next.f.s<cols && field[next.f.f][next.f.s]!='*' && next.s!=current.s){
				// cout << "(" << next.f.f << ", " << next.f.s << ")" << endl;
				if (mirror[next.f.f][next.f.s]>mirror[current.f.f][current.f.s]+1){
					mirror[next.f.f][next.f.s]=mirror[current.f.f][current.f.s]+1;
					q.push(next);
				}
				next = mp(mp(next.f.f+dx[i], next.f.s+dy[i]), dir[i]);
			}
		}
	}
	cout << mirror[end.f][end.s] - 1 << endl;
}