#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 1e9 + 7;

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
    i64 n;
    cin >> n;

    if (n <= 6) {
        if (n == 1) {
            cout << 1 << '\n';
        }else if (n == 2) {
            cout << 2 << '\n';
        }else if (n == 3) {
            cout << 4 << '\n';
        }else if (n == 4) {
            cout << 8 << '\n';
        }else if (n == 5) {
            cout << 16 << '\n';
        }else {
            cout << 32 << '\n';
        }
        return;
    }

    mtx mt(6, 6);
    mtx t(1, 6);
    for (int j = 1; j <= 6; j++) {
        mt.a[j][1] = 1;
    }

    mt.a[1][2] = 1;
    mt.a[2][3] = 1;
    mt.a[3][4] = 1;
    mt.a[4][5] = 1;
    mt.a[5][6] = 1;

    t.a[1][1] = 32;
    t.a[1][2] = 16;
    t.a[1][3] = 8;
    t.a[1][4] = 4;
    t.a[1][5] = 2;
    t.a[1][6] = 1;

    mtx res = t * qpow(mt, n - 6);
    cout << res.a[1][1] << '\n';
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