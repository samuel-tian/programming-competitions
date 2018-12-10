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

int n;
vector<string> adj[30];
string missing[100];
string kthcow(int k, int numadj){
	string ans = "";
	int choices = 1;
	for (int i = 0; i < numadj; i++){
		choices *= adj[i].size();
	}
	for (int i = 0; i < numadj; i++){
		choices /= adj[i].size();
		ans += (adj[i][k / choices] + " ");
		k = k % choices;
		// cout << k << endl;
	}
	// cout << ans << endl;
	return ans;
}
int missingbefore(string cow, int numadj){
	int counter = 0;
	for (int i = 0; i < n; i++){
		if (missing[i] <= cow) counter++;
	}
	// cout << counter << " - ";
	return counter;
}
int main(){
	int k;
	cin >> n >> k;
	string farmer, john, has, no, temp;
	for (int i = 0; i < n; i++){
		cin >> farmer >> john >> has >> no >> temp;
		int counter = 0;
		while (temp != "cow."){
			missing[i] += (temp + " ");
			bool already = false;
			for (int i = 0; i < adj[counter].size(); i++)
				if (adj[counter][i] == temp)
					already = true;
			if (already == false)
				adj[counter].pb(temp);
			counter++;
			cin >> temp;
		}
	}
	int numadj = 0;
	for (int i = 0; i < 30; i++)
		if (!adj[i].empty())
			numadj++;
	for (int i = 0; i < numadj; i++){
		sort(adj[i].begin(), adj[i].end());
	}
	for (int i = 0; i < n; i++){
		temp = missing[i].substr(0, missing[i].length() - 1);
		missing[i] = temp;
		// cout << missing[i] << endl;
	}
	int ans = k - 1;
	while (ans - missingbefore(kthcow(ans, numadj), numadj) < k-1){
		// cout << ans << endl;
		ans++;
	}
	cout << kthcow(ans, numadj) << endl;
}