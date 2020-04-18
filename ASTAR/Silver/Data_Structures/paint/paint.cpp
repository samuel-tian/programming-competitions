/*input

*/
#include <bits/stdc++.h>
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
#define MAXN 100010
#define debug cout << "pass" << endl;
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int main(){
	int n;
	//freopen("paint_cases\\10.out", "r", stdin); cin >> n; cout << n << endl; fclose(stdin);
	//freopen("paint_cases\\10.in", "r", stdin);
	cin >> n;
	int moves[n];
	for (int i = 0; i < n; i++){
		char temp;
		cin >> moves[i] >> temp;
		if (temp == 'L') moves[i] *= -1;
	}
	map<int, int> points;
	points[0] = 0;
	int current = 0;
	for (int i = 0; i < n; i++){
		current += moves[i];
		if (moves[i] < 0){
			points[current]++;
			points[current-moves[i]]--;
		}
		else if (moves[i] > 0){
			points[current]--;
			points[current-moves[i]]++;
		}
	}
	map<int, int>::iterator iter = points.begin();
	int runsum = 0;
	int counter = 0;
	while (iter != points.end()){
		runsum += iter->second;
		if (runsum >= 2)
			counter -= iter->first;
		iter++;
		if (runsum >= 2)
			counter += iter->first;
	}
	cout << counter << endl;
	//fclose(stdin);
}