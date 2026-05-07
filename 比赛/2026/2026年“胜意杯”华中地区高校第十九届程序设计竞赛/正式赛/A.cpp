#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 998244353;

char *p1, *p2, buf[100000];
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++)

i64 read () {
    i64 x = 0, f = 1;
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

i64 qpow (i64 a, i64 b)
{
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve ()
{
    int n = read();
    int s = read();
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        v[i] = read();
    }
    vector <i64> p(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = read();
    }

    vector <int> ml(n + 1), mr(n + 1);
    ml[s] = v[s];
    for (int i = s - 1; i >= 1; i--) {
        ml[i] = max(ml[i + 1], v[i]);
    }
    for (int i = s + 1; i <= n; i++) {
        mr[i] = max(mr[i - 1], v[i]);
    }

    vector <vector <i64> > inv(n + 1, vector <i64> (n + 1, 0));
    vector <i64> pre(n + 5, 1);
    for (int l = 1; l <= s - 1; l++) {
        for (int r = s + 1; r <= n; r++) {
            i64 t = (p[l] + p[r]) % mod;
            pre[r + 1] = pre[r] * t % mod;
        }
        i64 x = qpow(pre[n + 1], mod - 2);
        for (int r = n; r >= s; r--) {
            i64 t = (p[l] + p[r]) % mod;
            inv[l][r] = x * pre[r] % mod;
            x = x * t % mod;
        }
    }

    vector <vector <i64> > dp(n + 1, vector <i64> (n + 1, 0));
    dp[s][s] = 1;
    i64 ans = 1;

    for (int len = 1; len <= n; len++) {
        int mnl = max(1, s - len + 1);
        int mxl = min(s, n - len + 1);
        for (int l = mnl; l <= mxl; l++) {
            int r = l + len - 1;
            if (dp[l][r] == 0) continue;
            if (l == 1 && r == n) continue;
            int mx = max(ml[l], mr[r]);
            if (l == 1) {
                dp[l][r + 1] = (dp[l][r + 1] + dp[l][r]) % mod;
                if (v[r + 1] > mx) {
                    ans = (ans + dp[l][r]) % mod;
                }
            }else if (r == n) {
                dp[l - 1][r] = (dp[l - 1][r] + dp[l][r]) % mod;
                if (v[l - 1] > mx) {
                    ans = (ans + dp[l][r]) % mod;
                }
            }else { 
                i64 t1 = dp[l][r] * p[l - 1] % mod * inv[l - 1][r + 1] % mod;
                i64 t2 = dp[l][r] * p[r + 1] % mod * inv[l - 1][r + 1] % mod;
                dp[l - 1][r] = (dp[l - 1][r] + t1) % mod;
                dp[l][r + 1] = (dp[l][r + 1] + t2) % mod;
                if (v[l - 1] > mx) {
                    ans = (ans + t1) % mod;
                }
                if (v[r + 1] > mx) {
                    ans = (ans + t2) % mod;
                }
            }
        }
    }
    
    cout << ans << '\n';
}   

int main ()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}   