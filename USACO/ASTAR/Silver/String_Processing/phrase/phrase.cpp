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
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;

int main(){														 // USACO
	string strm, strn; getline(cin, strm, ' '); getline(cin, strn);
	int m = atoi(strm.c_str());
	int n = atoi(strn.c_str());
	string phrases[m];
	pair<string,int> cows[n];
	for (int i = 0; i < m; i++) getline(cin, phrases[i]);
	for (int i = 0; i < n; i++) getline(cin, cows[i].first);
	for (int i = 0; i < n; i++) cows[i].second = cows[i].first.length();
	int count = 0;
	for (int j = 0; j < n; j++){
		for (int i = 0; i < m; i++){
			if (phrases[i].substr(0, cows[j].second)==cows[j].first){
				count++;
				break;
			}
		}
	}
	cout << count << endl;
}