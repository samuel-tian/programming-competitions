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

int main(){
	int b, e; cin >> b >> e;
	string bpath="", epath="";
	int bsum=0, esum=0;
	for (int i = 0; i < b; i++){
		int temp; string temp2;
		cin >> temp >> temp2;
		for (int j = 0; j < temp; j++)
			bpath += temp2;
	}
	for (int i = 0; i < e; i++){
		int temp; string temp2;
		cin >> temp >> temp2;
		for (int j = 0; j < temp; j++)
			epath += temp2;
	}
	// cout << bpath << endl << epath << endl;
	int counter = 0;
	int ecur = 0, bcur = 0;
	int eprev = 0, bprev = 0;
	for (int t = 0; t < max(bpath.length(), epath.length()); t++){
		eprev = ecur;
		bprev = bcur;
		if (t < epath.length()){
			if (epath[t] == 'R') ecur++;
			else if (epath[t] == 'L') ecur--;
		}
		if (t < bpath.length()){
			
			if (bpath[t] == 'R') bcur++;
			else if (bpath[t] == 'L') bcur--;
		}
		if (eprev != bprev && ecur == bcur){
			counter++;
			//cout << "time" sp t << endl;
			//cout << ecur sp bcur << endl;
		}
		//cout << "time" sp t+1 << endl;
		//cout << "e" sp eprev sp ecur sp "b" sp bprev sp bcur << endl;
	}
	cout << counter << endl;
}