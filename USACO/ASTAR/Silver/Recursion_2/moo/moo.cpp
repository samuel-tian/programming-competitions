#include <iostream>
#define endl "\n"
using namespace std;

int length(int n){
    if (n==0) return 3;
    else return (2 * length(n-1) + n + 3);
}

string moo(int index, int n){
    if (n==0){
        if (index == 0) return "m";
        else return "o";
    }
    else{
        if (index < length(n-1)){
            return moo(index, n - 1);
        }
        else if (index >= length(n-1) && index < (length(n-1) + n + 3)){
            index -= length(n-1);
            if (index == 0) return "m";
            else return "o";
        }
        else{
            index -= (length(n-1) + n + 3);
            return moo(index, n-1);
        }
    }
}

int main(){
    int index;
    cin >> index;
    int n = 0;
    while (length(n) < index){
        n++;
    }
    cout << moo(index - 1, n) << endl;
}
