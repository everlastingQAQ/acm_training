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

    i64 ans = 1e11;
    auto dfs = [&] (auto self, i64 t1, i64 t2, int u) -> void {
        if (u == n + 1) {
            ans = min(ans, abs(t1 - t2));
            return;
        }
        self(self, t1 + v[u], t2, u + 1);
        self(self, t1, t2 + v[u], u + 1);
    };
    dfs(dfs, 0LL, 0LL, 1);

    cout << ans << '\n';
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