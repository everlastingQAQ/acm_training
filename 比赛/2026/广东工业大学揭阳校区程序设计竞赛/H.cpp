#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

char *p1,*p2,buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
i64 read()
{
    int x=0,f=1;
    char ch=nc();
    while(ch<48||ch>57)
    {
        if(ch=='-')
            f=-1;
        ch=nc();
    }
    while(ch>=48&&ch<=57)
        x=x*10+ch-48,ch=nc();
   	return x*f;
}

const int mod = 1e9 + 7;

struct mtx {
    int n, m;
    i64 a[6][6];

    mtx (int n = 0, int m = 0) : n(n), m(m) {
        memset(a, 0, sizeof(a));
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
                    res.a[i][j] = (res.a[i][j] + (__int128)a[i][k] * other.a[k][j] % mod) % mod;
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
    i64 n = read();

    if (n <= 4) {
        if (n == 0) {
            cout << 1 << '\n';
        }else if (n == 1) {
            cout << 1 << '\n';
        }else if (n == 2) {
            cout << 109 << '\n';
        }else if (n == 3) {
            cout << 620 << '\n';
        }else {
            cout << 3350 << '\n';
        }
        return;
    }

    mtx mt(5, 5);
    mtx a(1, 5);
    mt.a[1][1] = 1, mt.a[1][2] = 1, mt.a[1][3] = 0, mt.a[1][4] = 0, mt.a[1][5] = 0;
    mt.a[2][1] = 2, mt.a[2][2] = 0, mt.a[2][3] = 0, mt.a[2][4] = 0, mt.a[2][5] = 0;
    mt.a[3][1] = 3, mt.a[3][2] = 0, mt.a[3][3] = 1, mt.a[3][4] = 0, mt.a[3][5] = 0;
    mt.a[4][1] = 3, mt.a[4][2] = 0, mt.a[4][3] = 1, mt.a[4][4] = 1, mt.a[4][5] = 0;
    mt.a[5][1] = 20, mt.a[5][2] = 0, mt.a[5][3] = 0, mt.a[5][4] = 0, mt.a[5][5] = 5;

    a.a[1][1] = 1, a.a[1][2] = 1, a.a[1][3] = 1, a.a[1][4] = 1, a.a[1][5] = 5;

    mtx res = a * qpow(mt, n - 1);
    printf("%lld\n", res.a[1][1]);
}

int main ()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int _ = read();
    while (_--) {
        solve();
    }
    return 0;
}