/*input
())(
*/

#include <iostream>
#include <string>

using namespace std;

#define endl '\n'
#define MAXN 100000

int main() {
	string str;
	int counter = 0, switches = 0;
	cin >> str;
	for (int i = 0; i < str.length(); ++i) {
		str[i] == '(' ? ++counter : --counter;
		if (counter < 0) {
			// str[i] = '(';
			counter += 2;
			++switches;
		}
	}
	// cout << str << endl;
	cout << switches + counter / 2 << endl;
}