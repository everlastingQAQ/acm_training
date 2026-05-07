#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

char *p1, *p2, buf[100000];
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++)

int read()
{
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

i64 qpow (i64 a, i64 b)
{
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve ()
{
    int n = read();
    unordered_map <int, int> mp;
    
    vector <int> v(n + 1);
    set <int> st;
    for (int i = 1; i <= n; i++) {
        v[i] = read();
        mp[v[i]]++;
        st.insert(v[i]);
    }

    if (mp[1]) {
        for (int i = 1; i <= n; i++) {
            if (v[i] != 1 && mp[v[i]] >= 2) {
                cout << "YES\n";
                return;
            }
        }
    }

    for (auto x : st) {
        if (x == 1) continue;
        for (auto y : st) {
            if (y == 1) continue;
            // if (x == y && mp[x] < 2) continue;
            if (y > 32) break;
            i64 t = qpow(x, y);
            if (t > 1e9) break;
            // cout << x << ' ' << y << ' ' << t << '\n';
            if (mp[t]) {
                printf("YES\n");
                return;
            }
        }
    }

    printf("NO\n");
}

int main ()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int _ = read();
    while (_--) {
        solve();
    }
    return 0;
}