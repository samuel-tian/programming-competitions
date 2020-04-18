#include <iostream>
#define endl "\n"
using namespace std;

void combo(int current, int numindicies, int numdigits, int digits[], int indicies[]){
    if (current==numindicies){
        for (int i = 0; i < numindicies; i++){
            cout << digits[indicies[i]];
        }
        cout << endl;
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

