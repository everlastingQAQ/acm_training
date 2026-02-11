#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, s;
    cin >> n >> s;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    sort(v.begin() + 1, v.end());
    int ans = 0;
    auto dfs = [&] (int sum, int i, auto self) -> void {
        if (i > n) {
            if (sum == s) ans++;
            return;
        }
        if (sum > s) {
            return;
        }
        self(sum + v[i], i + 1, self);
        self(sum, i + 1, self);

    };
    dfs(0, 1, dfs);

    cout << ans << '\n';
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/