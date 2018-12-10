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

string coggle[5][5];
bool used[5][5];
vector<string> dictemp, dictemp2, dict[26];
set<string> ans;
int counter;
void recurse(string word, int r, int c){
	vector<string> temptemp;
	// cout << r sp c << endl;
	// cout << word sp r sp c << endl;
	bool end = false, start = true;
	for (int i = 0; i < dictemp.size(); ++i){
		if (end == true && start == false) break;
		if (dictemp[i].substr(0, word.length()) == word){
			temptemp.pb(dictemp[i]);
			start = false;
		}
		if (dictemp[i].substr(0, word.length()) != word && start == false)
			end = true;
		if (dictemp[i] == word){
			//cout << word << endl;
			ans.insert(word);
		}
	}
	dictemp = temptemp;
	if (dictemp.empty()){
		dictemp = dictemp2;
		return;
	}
	int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
	int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};
	for (int i = 0; i < 8; ++i){
		int nr = r + dx[i];
		int nc = c + dy[i];
		if (nr>=0 && nr<5 && nc>=0 && nc<5 && used[nr][nc] == false){
			used[nr][nc] = true;
			recurse(word + coggle[nr][nc], nr, nc);
			used[nr][nc] = false;
		}
	}
	return;
}
int main(){
	string temp;
	//freopen("coggle_cases\\coggle.1.in", "r", stdin);
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			cin >> coggle[i][j];
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			cout << coggle[i][j] << " ";
		}
		cout << endl;
	}
	//fclose(stdin);
	//freopen("coggle_cases\\coggle.dict.txt", "r", stdin);
	while (cin >> temp){
		dict[temp[0] - 65].pb(temp);
	}
	//fclose(stdin);
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			dictemp = dict[coggle[i][j][0] - 65];
			dictemp2 = dictemp;
			used[i][j] = true;
			recurse(coggle[i][j], i, j);
			used[i][j] = false;
		}
	}

	cout << ans.size() << endl;
}