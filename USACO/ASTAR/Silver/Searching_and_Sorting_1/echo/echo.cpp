#include <iostream>
using namespace std;

int main(){
    int maxlength = 0, position, position2;
    string echo1, echo2, substring, substring2;
    cin >> echo1 >> echo2;
    for (int sub1 = 1; sub1 <= echo1.length(); sub1++){
        substring = echo1.substr(0, sub1);
        position = echo2.find(substring);
        if (position + sub1 == echo2.length() && position != -1){
            maxlength = sub1;
        }
    }
    for (int sub2 = 1; sub2 <= echo2.length()-1; sub2++){
        substring2 = echo2.substr(0, sub2);
        position2 = echo1.find(substring2);
        if (position2 + sub2 == echo1.length() && sub2 > maxlength && position2 != -1){
            maxlength = sub2;
        }
    }
    cout << maxlength << endl;
}
