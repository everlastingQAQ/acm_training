#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    bool ok = false;
    while (n--) {
        int t;
        cin >> t;
        if (t == 100) ok = true;
    }
    cout << (ok ? "Yes" : "No") << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}