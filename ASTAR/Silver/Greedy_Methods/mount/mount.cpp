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
#define maxn 10000
#define debug cout << "pass" << endl;
// #define bitSize 262144	/*smallest pow of 2 bigger than size of array */
// #define bitSize2 bitSize*2
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;

int heights[maxn], n;
int base(int current){
	int next = current - 1;
	// cout << "next" sp next sp current << endl;
	while (heights[next] == heights[current] && next>=0){
		next--;
		current--;
	}
	return current;
}
pii highest(int current){
	current = base(current);
	if (current == n) return mp(n, 0);
	int next = current + 1; int counter = 1;
	while (heights[next]>=heights[current] && next < n){
		// cout << current << " ";
		next++;
		current++;
		counter++;
	}
	// cout << endl;
	// cout << "highest" sp current << endl;
	return mp(current, counter);
}
pii end_mount(int current){
	if (current == n) return mp(n, 0);
	int next = current + 1; int counter = 0;
	while (heights[next]<=heights[current] && next < n){
		// cout << current << " ";
		next++;
		current++;
		counter++;
	}
	// cout << endl;
	if (next >= n) return mp(n, counter);
	return mp(current, counter);
}
int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> heights[i];
		// cout << heights[i] << " ";
	}
	// cout << endl;
 	int current = 0;
 	int maxwidth = 0;
 	//cout << highest(current).f sp highest(current).s << endl << end_mount(highest(current).f).f sp end_mount(highest(current).f).s << endl;
 	// 7 3 2 3 5 4 1 6
	while (current < n && current != n){
		int width = 0;
		pii temp = highest(current);	
		width += temp.s;
		// cout << width << endl;
		pii temp2 = end_mount(temp.f);
		width += temp2.s;
		current = temp2.f;
		// cout << "width" sp width << endl;
		maxwidth = max(maxwidth, width);
	}
	cout << maxwidth << endl;
}