#include <cstdio>
#include <algorithm>
using namespace std;

FILE *in = fopen ("protest.in", "r"), *out = fopen ("protest.out", "w");

const int MAXN = 100005, MOD = 1000000009;

int N, A [MAXN], tree [MAXN];
int P, psums [MAXN];

inline int search (int val)
{
    return lower_bound (psums, psums + P, val) - psums;
}

inline int query (int x)
{
    int sum = 0;

    for (int i = x + 1; i > 0; i -= i & -i)
        sum = (sum + tree [i]) % MOD;

    return sum;
}

inline void update (int x, int val)
{
    for (int i = x + 1; i <= P; i += i & -i)
        tree [i] = (tree [i] + val) % MOD;
}

int main ()
{
    fscanf (in, "%d", &N);
    psums [0] = 0;

    for (int i = 0; i < N; i++)
    {
        fscanf (in, "%d", A + i);
        psums [i + 1] = psums [i] + A [i];
    }

    P = N + 1;
    sort (psums, psums + P);
    P = unique (psums, psums + P) - psums;
    update (search (0), 1);
    int dp, sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum += A [i];
        dp = query (search (sum));
        update (search (sum), dp);
    }

    fprintf (out, "%d\n", dp);
    return 0;
}
