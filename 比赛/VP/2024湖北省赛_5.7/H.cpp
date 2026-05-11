#include <bits/stdc++.h>
using namespace std;
#define int long long

int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, -1, 0, 1};

void solve ()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector <array <int, 3> > v(k + 1);
    vector <array <int, 2> > pos;
    map <array <int, 2>, bool> mp;
    int mask = 0;
    for (int i = 1; i <= k; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        mask |= v[i][2] << (i * 2);
        for (int j = 0; j < 5; j++) {
            int xx = v[i][0] + dx[j];
            int yy = v[i][1] + dy[j];
            if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
            if (mp[{xx, yy}]) continue;
            mp[{xx, yy}] = true;
            pos.push_back({xx, yy});
        }
    }
    
    vector <int> a;
    for (auto [x, y] : pos) {
        int mask = 0;
        for (int i = 1; i <= k; i++) {
            int dist = abs(x - v[i][0]) + abs(y - v[i][1]);
            if (dist <= 1) {
                mask |= (1 << i);
            }
        }
        if (mask) a.push_back(mask);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    vector <int> dp(mask + 10, 1e18);
    dp[mask] = 0;
    for (; mask >= 0; mask--) {
        if (dp[mask] == 1e18) continue;
        for (auto x : a) {
            int t = mask;
            for (int i = 1; i <= k; i++) {
                if ((x >> i) & 1) {
                    if (((t >> (2 * i)) & 3) > 0) {
                        t -= 1 << (2 * i);
                    }
                }
            }
            dp[t] = min(dp[t], dp[mask] + 1);
        }
    }
    cout << dp[0] << '\n';
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