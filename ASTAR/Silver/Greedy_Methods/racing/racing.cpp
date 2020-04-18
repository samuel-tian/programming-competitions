/*input
13 5 3 2 1
u
f
u
d
f
*/
#include <iostream>
using namespace std;

int main(){
    int m, t, u, f, d;
    cin >> m >> t >> u >> f >> d;
    char input;
    int path[t];
    for (int i = 0; i < t; i++){
        cin >> input;
        if (input == 'u' || input == 'd') path[i] = u + d;
        else path[i] = 2 * f;
    }
    int sum = 0, longer;
    for (int longest = 0; longest < t; longest++){
        sum += path[longest];
        if (sum > m){
            sum -= path[longest];
            longer = longest;
            break;
        }
    }
    cout << longer << endl;
}