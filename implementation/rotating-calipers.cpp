//
// Created by samue on 12/22/2019.
//

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'

const int MAXN = 50005;
const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name == "input") {
        freopen("input.txt","r",stdin);
    }
    else {
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
    }
}

int dist(pi a, pi b) {
    return (a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s);
}

int area(int aa, int bb, int cc, vector<pii> hull) {
    pi a = hull[aa].f;
    pi b = hull[bb].f;
    pi c = hull[cc].f;
    return (a.f * (b.s - c.s) + b.f * (c.s - a.s) + c.f * (a.s - b.s));
}

int ccw(pi a, pi b, pi c) {
    return (b.f-a.f) * (c.s-a.s) - (b.s-a.s) * (c.f-a.f);
}

int n;
pii points[MAXN];

vector<pii> convexHull() {
    vector<pii> hull;
    int minIndex = -1;
    int minX = INF;
    for (int i = 0; i < n; ++i) {
        if (points[i].f.f < minX) {
            minX = points[i].f.f;
            minIndex = i;
        }
    }
    vector<pair<double, pii> > angles;
    for (int i = 0; i < n; ++i) {
        int dx = points[i].f.f - points[minIndex].f.f;
        int dy = points[i].f.s - points[minIndex].f.s;
        if (dx == 0 && dy == 0) {
            angles.pb(mp((double)NINF, points[i]));
        }
        else {
            angles.pb(mp(atan2(dy, dx), points[i]));
        }
    }
    sort(angles.begin(), angles.end());
    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 1].f, hull[hull.size() - 2].f, angles[i].s.f) > 0) {
            hull.pop_back();
        }
        hull.pb(angles[i].s);
    }
    return hull;
}

#define NEXT(i, s) (i + 1) % (s)

vpi antipodalPairs() {
    vector<pii> hull = convexHull();
    for (int i = 0; i < hull.size(); ++i) {
        cout << hull[i].f.f << " " << hull[i].f.s << endl;
    }
    vpi antipodes;
    int si = hull.size();
    int p0 = si - 1;
    int q0;
    int p = 0;
    int q = NEXT(p, si);
    while (area(p, NEXT(p, si), NEXT(q, si), hull) > area(p, NEXT(p, si), q, hull)) {
        q = NEXT(q, si);
        q0 = q;
    }
    while (q != p0) {
        p = NEXT(p, si);
        antipodes.pb(mp(p, q));
        while (area(p, NEXT(p, si), NEXT(q, si), hull) > area(p, NEXT(p, si), q, hull)) {
            q = NEXT(q, si);
            if (mp(p, q) != mp(q0, p0)) {
                antipodes.pb(mp(hull[p].s, hull[q].s));
            }
            else return antipodes;
        }
        if (area(q, NEXT(p, si), NEXT(q, si), hull) == area(p, NEXT(p, si), q, hull)) {
            if (mp(p, q) != mp(q0, p0)) {
                antipodes.pb(mp(hull[p].s, hull[NEXT(q, si)].s));
            }
            else {
                antipodes.pb(mp(hull[NEXT(p, si)].s, hull[q].s));
            }
        }
    }
}

pii rotatingCalipers() {
    vector<pii> hull = convexHull();
    vpi antipodes = antipodalPairs();
    pii ret = mp(mp(-1, -1), INF);
    for (int i = 0; i < antipodes.size(); ++i) {
        int l = antipodes[i].f;
        int r = antipodes[i].s;
        if (dist(hull[l].f, hull[r].f) <= ret.s) {
            int mi = min(hull[l].s, hull[r].s);
            int ma = max(hull[l].s, hull[r].s);
            if (dist(hull[l].f, hull[r].f) == ret.s) {
                ret.f = min(ret.f, mp(mi, ma));
            }
            else {
                ret.f = mp(mi, ma);
                ret.s = dist(hull[l].f, hull[r].f);
            }
        }
    }
    return ret;
}

int main() {
    setIO("input");
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].f.f >> points[i].f.s;
        points[i].s = i;
    }
    pii p = rotatingCalipers();
    cout << p.f.f << " " << p.f.s << endl;
}
