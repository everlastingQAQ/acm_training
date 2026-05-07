#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n;
    cin >> n;
    i64 m = sqrtl(n);
    if (m * m != n) {
        cout << "NO\n";
        return;
    }
    auto cal = [&] (i64 x) -> bool {
        string s = to_string(x);
        string ss = s;
        reverse(ss.begin(), ss.end());
        return s == ss;
    };

    if (cal(n) && cal(m)) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}