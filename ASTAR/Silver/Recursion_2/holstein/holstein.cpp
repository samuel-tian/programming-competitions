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
	int v; cin >> v;
	int req[v]; for (int i = 0; i < v; i++) cin >> req[i];
	int g; cin >> g;
	int vit[g][v];
	// int test = 0; // DEBUG

	for (int i = 0; i < g; i++){
		for (int j = 0; j < v; j++){
			cin >> vit[i][j];
		}
	}
	int minvits = inf;
	vector<int> final;
	for (int x = 1; x < (1<<g); x++){
		// cout << "x" sp x << endl; // DEBUG
		int counter = 0, sum[v];
		for (int i = 0; i < v; i++) sum[i] = 0;
		vector<int> current;
		for (int k = 0; k < g; k++){
			if ((x&(1<<k))>=1){
				// cout << 1; // DEBUG
				counter++;
				current.pb(k+1);
				for (int l = 0; l < v; l++)
					sum[l] += vit[k][l];
			}
			// else cout << 0; // DEBUG
		}
		// cout << endl; // DEBUG
		bool enough = true;
		for (int i = 0; i < v; i++){
			// cout << sum[i] << " "; // DEBUG
			if (sum[i] < req[i]){
				enough = false;
				break;
			}
		}
		// cout << endl; // DEBUG
		if (enough == true && counter < minvits){
			minvits = counter;
			final.clear();
			for (int i = 0; i < minvits; i++)
				final.pb(current[i]);
			// test = x; // DEBUG
		}
	}
	// cout << test << " "; // DEBUG
	cout << minvits;
	for (int i = 0; i < final.size(); i++)
		cout << " " << final[i];
	cout << endl;
}