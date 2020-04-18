#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

bool same = 1;

void combo(int current, int numindicies, int numdigits, int digits[], vector<int> indicies, int temp[]){
    if (current==numindicies){
        for (int i = 0; i < numindicies; i++){
            for (int j = i + 1; j < numindicies; j++){
                if (indicies[i] == indicies[j]){
                    same = 0;
                }
            }
        }
        for (int a = 0; a < numindicies; a++){
            for (int b = a + 1; b < numindicies; b++){
                if (temp[indicies[a]] > temp[indicies[b]]) same = 0;
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
            combo(current + 1, numindicies, numdigits, digits, indicies, temp);
            indicies[current+1] = 0;
            indicies[current]++;
        }
    }
}

int main(){
    int n, k, input;
    cin >> n;
    int digits[n];
    int temp[n];
    for (int j = 0; j < n; j++){
        cin >> input;
        temp[j] = j;
        digits[j] = input;
    }
    vector<int> indicies;
    for (int k = 1; k <= n; k++){
        for (int i = 0; i < k; i++){
            indicies.push_back(0);
        }
        combo(0, k, n, digits, indicies, temp);
    }
}

