#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    i64 c;
    cin >> n >> c;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int ans = n;
    vector <int> vis(n + 1, 0);
    int cnt = 0;
    auto dfs = [&] (auto self, i64 sum, int u) -> void {
        if (u == n + 1) {
            ans = min(ans, cnt);
            return;
        }
        sum += v[u];
        if (sum < c) {
            self(self, sum, u + 1);
            
        }else {
            cnt++;
            self(self, v[u], u + 1);
            cnt--;
        }
    };
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