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
typedef pair<int,string> sii;

int main(){
	int n;
	cin >> n;
	sii queue[n];
	for (int i = 0; i < n; i++){
		cin >> queue[i].first >> queue[i].second;
		bool boolean = true;
		int counter = 0;
		for (int j = 0; j < queue[i].first; j++){
			if (queue[i].second[j]=='>') counter ++;
			else counter--;
			if (counter < 0){
				boolean = false;
				cout << "illegal" << endl;
				break;
			}
		}
		if (boolean == true){
			if (counter != 0) cout << "illegal" << endl;
			else cout << "legal" << endl;
		}
	}
	
}