#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = n - 1; i >= 1; i--) {
        if (v[i] < v[i] + v[i + 1]) {
            v[i] = v[i] + v[i + 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (v[i] > 0);
    }
    cout << ans << '\n';
}

int32_t main ()
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