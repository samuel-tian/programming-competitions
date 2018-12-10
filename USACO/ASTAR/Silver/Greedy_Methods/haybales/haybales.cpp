#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int heights[n], input, average = 0, above = 0;
    for (int i = 0; i < n; i++){
        cin >> input;
        heights[i] = input;
        average += input;
    }
    average /= n;
    for (int j = 0; j < n; j++){
        if (heights[j] > average) above += (heights[j] - average);
    }
    cout << above << endl;
}