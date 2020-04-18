#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pair
#define endl '\n'
#define sp << ' ' <<
#define inf 2000000000
#define MAXN 100010
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int main(){
	int n, c;
	freopen("crazy_cases\\1.out", "r", stdin); cin >> n; cout << "ans" sp n << endl; fclose(stdin);
	freopen("crazy_cases\\1.in", "r", stdin);
	cin >> n >> c;
	pair<pii, pii> fences[n];
	pii cows[c];
	for (int i = 0; i < n; i++)
		cin >> fences[i].f.f >> fences[i].f.s >> fences[i].s.f >> fences[i].s.s;
	for (int i = 0; i < c; i++)
		cin >> cows[i].f >> cows[i].s;
	fclose(stdin);
}