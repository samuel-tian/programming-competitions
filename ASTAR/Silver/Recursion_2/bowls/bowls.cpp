/*input
0 0 1 1 1 0 0 1 1 0 1 1 0 0 0 0 0 0 0 0
*/
#include <iostream>
#define endl "\n";
using namespace std;

int mincount = 21, bowlscopy[20], flips[20];
void flip(int n, int bowls[20]){
    if (n==20){
        for (int j = 0; j < 20; j++) bowlscopy[j] = bowls[j];
        // flip the bowls
        for (int i = 0; i < 20; i++){
            if (flips[i]==1){
                if (i==0){
                    bowlscopy[0] = (bowlscopy[0] + 1)%2;
                    bowlscopy[1] = (bowlscopy[1] + 1)%2;
                }
                else if (i==19){
                    bowlscopy[18] = (bowlscopy[18]+1)%2;
                    bowlscopy[19] = (bowlscopy[19]+1)%2;
                }
                else{
                    bowlscopy[i-1]=(bowlscopy[i-1]+1)%2;
                    bowlscopy[i]=(bowlscopy[i]+1)%2;
                    bowlscopy[i+1]=(bowlscopy[i+1]+1)%2;
                }
            }
        }
        // check if the bowls are flipped
        bool flipped = true;
        for (int a=0; a<20; a++){
            if (bowlscopy[a]==1) flipped = false;
        }
        // determine count
        int ccount = 0;
        bool finished = true;
        for (int b=0; b<20; b++){
            if (flips[b]==1) ccount++;
            if (flips[b]==0) finished = false;
        }
        if (flipped==true && ccount < mincount) mincount = ccount;

        if (finished==false) return;
    }
    else{
        flips[n] = 0;
        flip(n+1, bowls);
        flips[n] = 1;
        flip(n+1, bowls);
    }
}

int main(){
    int bowls[20], input;
    for (int q = 0; q < 20; q++){
        cin >> input;
        bowls[q] = input;
    }
    flip(0, bowls);
    cout << mincount << endl;
}
// 0 0 1 1 1 0 0 1 1 0 1 1 0 0 0 0 0 0 0 0
