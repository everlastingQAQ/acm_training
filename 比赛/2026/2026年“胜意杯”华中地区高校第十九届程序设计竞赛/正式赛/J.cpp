#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 m = 1152921504606846976;

void solve ()
{
    map <array <i64, 2>, i64> mp1;
    mp1[{0, 0}] = 1;
    mp1[{m, 0}] = 1;
    mp1[{0, m}] = 1;
    map <i64, array <array <i64, 2>, 3> > mp2; 
    mp2[1][0] = {0, 0};
    mp2[1][1] = {m, 0};
    mp2[1][2] = {0, m};

    int q;
    cin >> q;
    while (q--) {
        string op;
        cin >> op;
        if (op == "query") {
            i64 x;
            cin >> x;
            auto [a, b, c] = mp2[x];
            cout << mp1[a] + mp1[b] + mp1[c] << '\n';
        }else if (op == "update") {
            i64 x, y;
            cin >> x >> y;
            auto [a, b, c] = mp2[x];
            mp1[a] = y;
            mp1[b] = y;
            mp1[c] = y; 
        }else {
            i64 x;
            cin >> x;
            auto [a, b, c] = mp2[x];
            array<i64, 2> ab = {(a[0] + b[0]) / 2, (a[1] + b[1]) / 2};
            array<i64, 2> ac = {(a[0] + c[0]) / 2, (a[1] + c[1]) / 2};
            array<i64, 2> bc = {(b[0] + c[0]) / 2, (b[1] + c[1]) / 2};
            mp2[x * 4] = {a, ab, ac};
            mp2[x * 4 + 1] = {ab, b, bc};
            mp2[x * 4 + 2] = {bc, ac, ab};
            mp2[x * 4 + 3] = {ac, bc, c};
            if (!mp1.count(ab)) mp1[ab] = 1;
            if (!mp1.count(ac)) mp1[ac] = 1;
            if (!mp1.count(bc)) mp1[bc] = 1;
        }
    }
}

int32_t main ()
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