#include <bits/stdc++.h>
using namespace std;
#define int long long

char *p1, *p2, buf[100000];
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++)

int read () {
    int x = 0, f = 1;
    char ch = gc();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = gc();
    }

    while ('0' <= ch && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = gc();
    }

    return x * f;
}

void solve ()
{
    int m = read();
    int res = 0; 
    for (int k = 0; k < m; k++) {
        int n = read();
        // if (n == 0) continue;
        int pmx = 63 - __builtin_clzll(n);
        if (pmx < 0) pmx = 0;
        int pmn = __builtin_ctzll(n);
        if (pmn == 32) pmn = 0;
        int ans = 0;
        int cur = 1;
        for (int i = pmx; i >= pmn; i--) {
            ans += cur * (n >> i & 1);
            cur *= 2;
        }
        res += ans;
    }
    printf("%lld", res);
}   

int32_t main ()
{
    solve();
    return 0;
}   