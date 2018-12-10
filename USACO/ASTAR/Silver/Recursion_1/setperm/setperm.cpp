#include <iostream>
#define endl "\n"
using namespace std;

bool same = 1;

void combo(int current, int numindicies, int numdigits, int digits[], int indicies[]){
    if (current==numindicies){
        for (int i = 0; i < numindicies; i++){
            for (int j = i + 1; j < numindicies; j++){
                if (indicies[i] == indicies[j]){
                    same = 0;
                }
            }
        }
        if (same == 1){
            for (int k = 0; k < numindicies; k++){
                cout << digits[indicies[k]];
            }
            cout << endl;
        }
        same = 1;
    }
    else{
        for (int j = 0; j < numdigits; j++){
            combo(current + 1, numindicies, numdigits, digits, indicies);
            indicies[current+1] = 0;
            indicies[current]++;
        }
    }
}

int main(){
    int n, k, input;
    cin >> n;
    int digits[n];
    for (int j = 0; j < n; j++){
        cin >> input;
        digits[j] = input;
    }
    cin >> k;
    int indicies[k];
    for (int i = 0; i < k; i++){
        indicies[i] = 0;
    }
    combo(0, k, n, digits, indicies);
}

