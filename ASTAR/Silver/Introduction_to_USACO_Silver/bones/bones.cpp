#include <iostream>
using namespace std;

int main(){
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int dicearray[s1 + s2 + s3 - 2];
    for (int roll = 0; roll < s1 + s2 + s3 -2; roll++){
        dicearray[roll] = 0;
    }
    for (int i = 1; i <= s1; i++){
        for (int j = 1; j <= s2; j++){
            for (int k = 1; k <= s3; k++){
                dicearray[i+j+k-2]++;
            }
        }
    }
    int largest = 0, largestval = 0;
    for (int value = 0; value < s1+s2+s3-2; value++){
        if (dicearray[value] > largest){
            largest = dicearray[value];
            largestval = value + 2;
        }
    }
    cout << largestval << endl;
}