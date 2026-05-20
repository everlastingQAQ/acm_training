#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> v(n + 1), pos(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pos[v[i]] = i;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans += (pos[i] < pos[i - 1]);
    }
    pos[0] = 0;
    pos[n + 1] = n + 1;

    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        set <int> st = {v[l], v[l] + 1, v[r], v[r] + 1};
        for (auto x : st) {
            if (x == 1 || x > n) continue;
            ans -= (pos[x] < pos[x - 1]);
        }
        swap(pos[v[l]], pos[v[r]]);
        swap(v[l], v[r]);
        for (auto x : st) {
            if (x == 1 || x > n) continue;
            ans += (pos[x] < pos[x - 1]);
        }
        cout << ans << '\n';
    }
}   

int32_t main ()
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