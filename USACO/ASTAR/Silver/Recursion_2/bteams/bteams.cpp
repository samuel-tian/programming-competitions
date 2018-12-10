#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int skill[12];
int cowteam[12];
int teamcount[4];
int output = 2000000000;
void recurse(int cow){
    if (cow == 12){
        int teamskill[4] = {0, 0, 0, 0};
        for (int i = 0; i < 12; i++){
            teamskill[cowteam[i]] += skill[i];
        }
        sort(teamskill, teamskill + 4);
        int mini = teamskill[0];
        int maxi = teamskill[3];
        if (maxi - mini < output) output = maxi - mini;
        return;
    }

    else{
        for (int j = 0; j < 4; j++){
            if (teamcount[j] <=2){
                cowteam[cow] = j;
                teamcount[j]++;
                recurse(cow+1);
                teamcount[j]--;
            }
        }
    }
}

int main(){
    int input;
    for (int a = 0; a < 12; a++){
        cin >> input;
        skill[a] = input;
    }
    recurse(0);
    cout << output << endl;
    return 0;
}
