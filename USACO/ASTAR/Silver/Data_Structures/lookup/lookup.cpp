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

int main(){														 // USACO
	int n; cin >> n;
	stack<pii> name;
	int ans[n];
	pii heights[n];
	for (int i = 0; i < n; i++){
		heights[i].first = i + 1;
		cin >> heights[i].second;
	}
	name.push(mp(0, inf));
	int current;
	for (int i = n - 1; i >= 0; i--){
		current = heights[i].second;
		if (current < name.top().second){
			ans[i] = name.top().first;
			name.push(mp(heights[i].first, heights[i].second));
		}
		else{
			name.pop();
			i++;
		}
	}
	for (int i = 0; i < n; i++){
		cout << ans[i] << endl;
	}
}