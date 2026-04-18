#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n = 8;
  	vector <vector <char> > v(n + 1, vector <char> (n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    i64 ans = 0;
    map <int, bool> mpa, mpb, mpc;
    auto dfs = [&] (auto self, int r) -> void {
        if (r == 9) {
            ans++;
            return;
        }
        for (int j = 1; j <= 8; j++) {
            if (v[r][j] == '*') continue;
            if (mpa[r - j + 8] || mpb[r + j] || mpc[j]) continue;
            mpa[r - j + 8] = true;
            mpb[r + j] = true;
            mpc[j] = true;
            self(self, r + 1);
            mpa[r - j + 8] = false;
            mpb[r + j] = false;
            mpc[j] = false;
        }
    };
    dfs(dfs, 1);
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