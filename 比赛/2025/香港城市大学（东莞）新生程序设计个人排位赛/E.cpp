#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> v(n + 1);
    i64 mx = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s >> v[i];
        if (s == "sensei") {
            mx = v[i];
        }
    }
    i64 ans = mx;
    for (int i = 1; i <= n; i++) {
        if (v[i] < mx) ans += v[i]; 
    }
    cout << ans << '\n';
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