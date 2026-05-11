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

    vector <array <int, 2> > ans;
    vector <int> vis(n + 1);
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] == 0) {    
            vis[i] = true;
            vis[i + 1] = true;
            ans.push_back({i - cnt, i - cnt + 1});
            i++;
            cnt++;
        }
    }

    if (!vis[n] && v[n] == 0) {
        ans.push_back({n - 1 - cnt, n - cnt});
        cnt++;
    }
    ans.push_back({1, n - cnt});

    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 