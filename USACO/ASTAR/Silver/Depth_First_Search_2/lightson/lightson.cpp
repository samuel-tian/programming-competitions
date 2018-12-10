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

vii toggle[100][100];
bool rooms[100][100];
bool used[100][100];
int main(){
	// freopen("lightson.in", "r", stdin);
	// freopen("lightson.out", "w", stdout);
	int n, m; cin >> n >> m;
	int xcor, ycor, switchx, switchy;
	for (int i = 0; i < m; i++){
		cin >> xcor >> ycor;
		cin >> switchx >> switchy;
		toggle[xcor-1][ycor-1].pb(mp(switchx-1, switchy-1));
		
	}
	/*for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << toggle[i][j].size();
		}
		cout << endl;
	}*/
	rooms[0][0] = true;
	used[0][0] = true;
	queue<pii> q;
	q.push(mp(0, 0));
	while (!q.empty()){
		pii current = q.front();
		// cout << current.f sp current.s << endl;
		q.pop();
		// cout << q.size() << endl;
		if (toggle[current.f][current.s].size() > 0){
			for (int i = 0; i < toggle[current.f][current.s].size(); i++)
				rooms[toggle[current.f][current.s][i].f][toggle[current.f][current.s][i].s] = true;
			toggle[current.f][current.s].clear();
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					used[i][j] = false;
			used[0][0] = true;
			q = queue<pii>();
			q.push(mp(0, 0));
			/*for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					cout << rooms[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;*/
		}
		else{
			int dx[4] = {1, -1, 0, 0};
			int dy[4] = {0, 0, 1, -1};
			for (int i = 0; i < 4; i++){
				pii next = mp(current.f+dx[i], current.s+dy[i]);
				if (next.f>=0 && next.f<n && next.s>=0 && next.s<n && rooms[next.f][next.s]==true && used[next.f][next.s] == false){
					used[next.f][next.s] = true;
					q.push(next);
				}
			}
		}
	}
	int counter = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (rooms[i][j] == true)
				counter++;
	cout << counter << endl;
}