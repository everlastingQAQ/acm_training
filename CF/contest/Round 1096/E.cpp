#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    i64 ans = 0;
    int mn = v[n];
    for (int i = n - 1; i >= 1; i--) {
        if (v[i] >= mn) {
            ans += v[i] - mn;
            v[i] = mn;
        }else {
            mn = v[i];
        }
    }

    int cur = 1;
    int mx = 0;
    for (int i = 2; i <= n; i++) {
        if (v[i] != v[i - 1]) {
            mx = max(mx, i - cur - 1);
            cur = i;
        }
    }
    if (v[n] == v[n - 1]) mx = max(mx, n - cur);
    cout << ans + mx << '\n';
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