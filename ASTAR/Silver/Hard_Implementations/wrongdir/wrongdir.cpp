/*input

*/
#include <bits/stdc++.h>
#define DEBUG
#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pair
#define endl '\n'
#define sp << ' ' <<
#define inf 2000000000
#define p 1000000007
#define eps 1e-9
#define MAXN 100000
#define debug cout << "pass" << endl;
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;

struct triple{ int x, y, dir; };
string path;
pair<triple, pii> tempend[MAXN];
int rx[4] = {0, 1, 0, -1};
int ry[4] = {1, 0, -1, 0};
pii combine(pii current, int curdir, int i){
	if (curdir == 0){
		current.f += tempend[i].s.f;
		current.s += tempend[i].s.s;
	}
	else if (curdir == 1){
		current.f += tempend[i].s.s;
		current.s -= tempend[i].s.f;
	}
	else if (curdir == 2){
		current.f -= tempend[i].s.f;
		current.s -= tempend[i].s.s;
	}
	else if (curdir == 3){
		current.f -= tempend[i].s.s;
		current.s += tempend[i].s.f;
	}
	return current;
}
void compute_f(){
	int curdir = 0;
	pii current = mp(0, 0);
	for (int i = 0; i < path.length(); i++){
		tempend[i].f.x = current.f;
		tempend[i].f.y = current.s;
		tempend[i].f.dir = curdir;
		if (path[i] == 'R') curdir = (curdir+1)%4;
		else if (path[i] == 'L') curdir = (curdir+3)%4;
		else{
			current.f += rx[curdir];
			current.s += ry[curdir];
		}
	}
}
void compute_s(){
	pii current = mp(0, 0);
	for (int i = path.length() - 1; i >= 0; i--){
		tempend[i].s = current;
		if (path[i] == 'R') current = mp(tempend[i].s.s, -tempend[i].s.f);
		else if (path[i] == 'L') current = mp(-tempend[i].s.s, tempend[i].s.f);
		else if (path[i] == 'F') current.s++;
	}
}
int main(){
	freopen("wrongdir_cases\\10.out", "r", stdin); int temp; cin >> temp; cout << temp << endl; fclose(stdin);
	freopen("wrongdir_cases\\10.in", "r", stdin);
	cin >> path; //cout << path << endl;
	set<pii> ending;
	compute_f();
	compute_s();
	/*for (int i = 0; i < path.length(); i++){
		cout << tempend[i].f.x sp tempend[i].f.y sp tempend[i].f.dir << '\t';
		cout << tempend[i].s.f sp tempend[i].s.s << endl;
	}*/
	for (int i = 0; i < path.length(); i++){
		if (path[i] == 'F'){
			pii current = mp(tempend[i].f.x, tempend[i].f.y);
			int curdir = tempend[i].f.dir;
			curdir = (curdir + 1) % 4;
			//cout << "curdir" sp curdir sp "current" sp current.f sp current.s << endl; //
			ending.insert(combine(current, curdir, i));
			//string tempstr = path; tempstr[i] = 'R';
			//cout << tempstr sp "direction" sp curdir sp "final" sp combine(current, curdir, i).f sp combine(current, curdir, i).s << endl;
			curdir = (curdir + 2) % 4;
			//cout << "curdir" sp curdir sp "current" sp current.f sp current.s << endl; //
			ending.insert(combine(current, curdir, i));
			//tempstr = path; tempstr[i] = 'L';
			//cout << tempstr sp "direction" sp curdir sp "final" sp combine(current, curdir, i).f sp combine(current, curdir, i).s << endl;
		}
		else if (path[i] == 'L'){
			pii current = mp(tempend[i].f.x, tempend[i].f.y);
			int curdir = tempend[i].f.dir;
			//curdir = (curdir + 1) % 4;
			current.f += rx[curdir]; current.s += ry[curdir];
			//cout << "curdir" sp curdir sp "current" sp current.f sp current.s << endl; //
			ending.insert(combine(current, curdir, i));
			//string tempstr = path; tempstr[i] = 'F';
			//cout << tempstr sp "direction" sp curdir sp "final" sp combine(current, curdir, i).f sp combine(current, curdir, i).s << endl;
			current.f -= rx[curdir]; current.s -= ry[curdir];
			curdir = (curdir + 1) % 4;
			//cout << "curdir" sp curdir sp "current" sp current.f sp current.s << endl; //
			ending.insert(combine(current, curdir, i));
			//tempstr = path; tempstr[i] = 'R';
			//cout << tempstr sp "direction" sp curdir sp "final" sp combine(current, curdir, i).f sp combine(current, curdir, i).s << endl;
		}
		else if (path[i] == 'R'){
			pii current = mp(tempend[i].f.x, tempend[i].f.y);
			int curdir = tempend[i].f.dir;
			//curdir = (curdir + 3) % 4;
			//cout << "curdir" sp curdir sp "current" sp current.f sp current.s << endl; //
			current.f += rx[curdir]; current.s += ry[curdir];
			ending.insert(combine(current, curdir, i));
			//string tempstr = path; tempstr[i] = 'F';
			//cout << tempstr sp "direction" sp curdir sp "final" sp combine(current, curdir, i).f sp combine(current, curdir, i).s << endl;
			current.f -= rx[curdir]; current.s -= ry[curdir];
			curdir = (curdir + 3) % 4;
			//cout << "curdir" sp curdir sp "current" sp current.f sp current.s << endl; //
			ending.insert(combine(current, curdir, i));
			//tempstr = path; tempstr[i] = 'L';
			//cout << tempstr sp "direction" sp curdir sp "final" sp combine(current, curdir, i).f sp combine(current, curdir, i).s << endl;
		}
	}
	cout << ending.size() << endl;
	fclose(stdin);
}