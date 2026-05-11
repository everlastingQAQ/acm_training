#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    i64 ans = 0;
    int cnt = 0;
    if (v[n] != 1) cnt = 0;
    else cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (v[i] == 1) continue;
        ans += v[i];
    }
    cout << ans + cnt << '\n';
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