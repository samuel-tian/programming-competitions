#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int order[n], bessie[n], total[2*n], input, counter = 0, wins = 0;
    for (int i = 0; i < n; i++){
        cin >> input;
        order[i] = input;
    }
    for (int j = 0; j < 2 * n; j++) total[j] = j + 1;
    for (int k = 0; k < n; k++){
        total[order[k] - 1] = 0;
    }
    for (int m = 0; m < 2 * n; m++){
        if (total[m] != 0){
            bessie[counter] = total[m];
            counter++;
        }
    }
    sort(order, order + n);
    sort(bessie, bessie + n);
    int smallestint = 0, currentint = 0;
    for (int turn = 0; turn < n; turn++){
        if (bessie[currentint] > order[smallestint]){
            currentint++;
            smallestint++;
            wins++;
        }
        else currentint++;
    }
    cout << wins << endl;
}
// 3 1 6 4 --> 2
