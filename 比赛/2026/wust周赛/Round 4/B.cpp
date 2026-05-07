#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, w;
    cin >> n >> w;
    vector <array <i64, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    sort(v.begin() + 1, v.end(), [] (auto a, auto b) {
        return a[0] > b[0];
    });

    i64 sum = 0;
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        if (sum + v[i][1] >= w) {
            ans += (w - sum) * v[i][0];
            break;
        }
        ans += v[i][0] * v[i][1];
        sum += v[i][1];
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