#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 998244353;

struct mtx {
    int n, m;
    vector <vector <i64> > a;

    mtx (int n = 0, int m = 0) : n(n), m(m) {
        a.assign(n + 1, vector <i64> (m + 1, 0));
    }

    static mtx I (int n) {
        mtx I(n, n);
        for (int i = 1; i <= n; i++) {
            I.a[i][i] = 1;
        }
        return I;
    }

    mtx operator * (const mtx& other) const {
        mtx res(n, other.m);
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= m; k++) {
                if (a[i][k] == 0) continue;
                for (int j = 1; j <= other.m; j++) {
                    res.a[i][j] = (res.a[i][j] + a[i][k] * other.a[k][j] % mod) % mod;
                }
            }
        }
        return res;
    }
};

mtx qpow (mtx a, i64 b) {
    mtx res = mtx::I(a.n);
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve ()
{
    
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}