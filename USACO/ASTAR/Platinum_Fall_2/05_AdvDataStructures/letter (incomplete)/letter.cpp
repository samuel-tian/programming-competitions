#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef long long ll;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a); i >= (b); --i)
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << " ";} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))

const int MAXN = 150005;
const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name == "input") {
        freopen("input.txt","r",stdin);
    }
    else if (name == "stdio") {

    }
    else {
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
    }
}

struct suffix {
    int id;
    pi rank;
};

int cmp(suffix a, suffix b) {
    return a.rank < b.rank;
}

int n, m;
string message, newspaper;
suffix r[MAXN]; // ranks
int suf[MAXN]; // suffix array
int lcp[MAXN];

void generate_suf(string s) {
    int t = s.size();
    FOR (i, 0, t) {
        r[i] = {i, mp(s[i] - 'A', (i == t-1) ? -1 : s[i+1]-'A')};
    }
    sort(r, r + t, cmp);
    int ind[t];
    for (int k = 4; k < 2 * t; k = k * 2) {
        int rank = 0;
        int prev_rank = r[0].rank.f;
        r[0].rank.f = rank;
        ind[r[0].id] = 0;
        FOR (i, 1, t) {
            if (r[i].rank.f == prev_rank && r[i].rank.s == r[i-1].rank.s) {
                prev_rank = r[i].rank.f;
                r[i].rank.f = rank;
            }
            else {
                prev_rank = r[i].rank.f;
                r[i].rank.f = ++rank;
            }
            ind[r[i].id] = i;
        }
        FOR (i, 0, t) {
            int next_index = r[i].id + k/2;
            if (next_index >= t) r[i].rank.s = -1;
            else r[i].rank.s = r[ind[next_index]].rank.f;
        }
        sort(r, r + t, cmp);
    }
    FOR (i, 0, t) {
        suf[i] = r[i].id;
    }
}

void generate_lcp(string s) {
    int t = s.size();
    int inv[t];
    FOR (i, 0, t) {
        inv[suf[i]] = i;
    }
    int k = 0;
    FOR (i, 0, t) {
        if (inv[i] == t-1) {
            k = 0;
            continue;
        }
        int j = suf[inv[i] + 1];
        while (i + k < t && j + k < t && s[i + k] == s[j + k]) k++;
        lcp[inv[i]] = k;
        if (k > 0) k--;
    }
}

int prefix(string str, int a, int b) {
    int ret = 0;
    a = suf[a];
    b = suf[b];
    while (max(a, b) + ret < str.size() && str[a + ret] == str[b + ret]) ++ret;
    return ret;
}

int main() {
    setIO("stdio");
    cin >> n >> m;
    int iter = 0;
    string in;
    while (iter < n) {
        cin >> in;
        newspaper += in;
        iter += in.size();
    }
    newspaper += ('?');
    iter = 0;
    while (iter < m) {
        cin >> in;
        message += in;
        iter += in.size();
    }
    string str = newspaper + message;
    generate_suf(str);
    generate_lcp(str);
    /*FOR (i, 0, str.size()) {
        cout << i << " " << str.substr(suf[i]) << " " << lcp[i] << endl;
    }*/
    int inv[str.size()];
    FOR (i, 0, str.size()) {
        inv[suf[i]] = i;
    }
    iter = 0;
    int ret = 0;
    while (iter < m) {
        int ind = inv[iter + n + 1];
//      cout << ind << " " << message.substr(iter) << endl;
        int l = ind, r = ind;
        while (l >= 0 && suf[l] >= n+1) {
            --l;
        }
        while (r < str.size() && suf[r] >= n+1) {
            ++r;
        }
        int lp = 0, rp = 0;
        if (l >= 0) lp = prefix(str, l, ind);
        if (r < str.size()) rp = prefix(str, r, ind);
        iter += max(lp, rp);
        ++ret;
    }
    cout << ret << endl;
}