#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k, m;
    cin >> n >> k >> m;
    string s = string(n, '.');
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        t--;
        s[t] = 'x';
    }

    vector <i64> a(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (abs(i - j) <= k) {
                a[i] |= (1LL << j);
            }
        }
    }

    vector <i64> dp(1LL << n, -1);
    auto dfs = [&] (auto self, i64 mask, int cnt) -> i64 {
        if (dp[mask] != -1) return dp[mask];
        if (cnt & 1) {
            dp[mask] = 1e11;
        }else {
            dp[mask] = -1e11;
        }

        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'x') continue;
            if ((mask >> i) & 1) continue;
            if ((mask & a[i]) != 0) continue;
            ok = true;
            i64 nxt = mask | (1LL << i);
            i64 val = self(self, nxt, cnt + 1);
            if (cnt & 1) {
                dp[mask] = min(dp[mask], val);
            }else {
                dp[mask] = max(dp[mask], val);
            }
        }

        if (!ok) {
            dp[mask] = cnt;
        }

        return dp[mask];
    };
    dfs(dfs, 0LL, 0LL);

    i64 mask = 0LL;
    int cnt = 0;
    
    while (1) {
        int t = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'x') continue;
            if ((mask >> i) & 1) continue;
            if ((mask & a[i]) != 0) continue;

            i64 nxt = mask | (1LL << i);
            if (dp[nxt] == dp[mask]) {
                t = i;
                break;
            }
        }
        if (t == -1) break;
        if (cnt & 1) {
            s[t] = 'b';
        }else {
            s[t] = 'a';
        }
        mask |= (1LL << t);
        cnt++;
    }

    cout << s << '\n';
}

int main ()
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