#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXS 100
#define MAXN 10000

struct Lesson {
	int start, length, skill;
	bool operator < (const Lesson& other) {
		if (start == other.start) {
			return length < other.length;
		}
		return start < other.start;
	}
};

struct Slope {
	int time, skill;
};

int main() {

}
