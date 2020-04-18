/*input
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/
#include <iostream>
#define endl "\n"
using namespace std;

void solve()
{
  	int bowlstate[20], bowlcopy[20];
  	int minflips = 2000000000;
  	for (int i = 0; i < 20; i++) cin >> bowlcopy[i];
  	for (int x = 0; x < 1<<20; x++){
    	for (int i = 0; i < 20; i++) bowlstate[i] = bowlcopy[i];
    	// convert to binary
    	int final[20];
    	for (int k = 0; k < 20; k++){
      		final[20-k-1] = 0;
      		if ((x & (1 << k)) > 0){
        		final[20-k-1]++;
      		}
    	}
    	int ones = 0;
    	bool possible = true;
    	for (int i = 0; i < 20; i++){
    		if (final[i]==1){
    			ones++;
	    		if (i==0){
	    			bowlstate[0] = (bowlstate[0] + 1) % 2;
	    			bowlstate[1] = (bowlstate[1] + 1) % 2;
	    		}
	    		else if (i==19){
	    			bowlstate[18] = (bowlstate[18] + 1) % 2;
	    			bowlstate[19] = (bowlstate[19] + 1) % 2;
	    		}
	    		else{
	    			bowlstate[i] = (bowlstate[i] + 1) % 2;
	    			bowlstate[i+1] = (bowlstate[i+1] + 1) % 2;
	    			bowlstate[i-1] = (bowlstate[i-1] + 1) % 2;
	    		}
	    	}
    	}
    	for (int i = 0; i < 20; i++){
    		if (bowlstate[i]==1) possible = false;
    	}
    	if (possible == true){
    		minflips = min(minflips, ones);
    	}

 	}
	
  	cout << minflips << endl;
}
int main()
{
  	solve();
}