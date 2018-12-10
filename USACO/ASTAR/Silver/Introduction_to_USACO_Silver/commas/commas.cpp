#include <iostream>
#include <string>
using namespace std;

int main(){
    string N;
    cin >> N;
    int length = N.length();
    if (length>=4) N = N.insert(length-3, ",");
    if (length>=7) N = N.insert(length-6, ",");
    if (length>=10) N = N.insert(length-9, ",");
    cout << N << endl;
}