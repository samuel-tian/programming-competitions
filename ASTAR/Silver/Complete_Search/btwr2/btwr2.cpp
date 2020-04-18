/*input
20
3288 6294
6562 5092
11328 2251
4128 9415
4752 9152
8146 5956
10210 3645
859 9063
5523 4448
9627 1801
8635 8258
10461 1756
7188 975
2592 6447
1945 6004
2302 2487
6211 5777
11522 9865
6720 3124
1680 7348
*/
#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{
    int n; cin >> n;
    pair<int,int> bales[n];
  	for (int i = 0; i < n; i++){
    	cin >> bales[i].first >> bales[i].second;
  	}
  	int maxbales = 0;
  	for (int x = 1; x < 1<<n; x++){
    	// convert to binary
    	int final[n]; // 
    	for (int k = 0; k < n; k++){
      		final[n-k-1] = 0;
      		if ((x & (1 << k)) > 0){
        		final[n-k-1]++;
      		}
    	}
    	int ones = 0;
    	for (int i = 0; i < n; i++){
      		if (final[i]==1) ones++;
    	}
    	pair<int,int> used[ones];
    	int counter = 0;
    	for (int i = 0; i < n; i++){
	      	if (final[i]==1){
	        	used[counter] = make_pair(bales[i].first, bales[i].second);
	        	counter++;
	      	}
    	}
    	sort(used, used + ones);
    	bool possible = true;
    	for (int i = 0; i < ones-1; i++){
      		if (used[i].second > used[i+1].second){
      			possible = false;
      			break;
      		}
    	}
    	if (possible == true){
      		maxbales = max(maxbales, ones);
    	}
  	}
  	cout << maxbales << endl;
}
int main()
{
  	solve();
}