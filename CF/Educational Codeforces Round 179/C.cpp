#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n;
    cin >> n;
    vector <int> v(n + 1);
    int mn = 1e11;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] != v[1]) ok = false;
        mn = min(mn, v[i]);
    }

    if (ok) {
        cout << 0 << '\n';
        return;
    }
    int ans = mn * (n - 1);

    map <int, vector <int> > mp;

    for (int i = 1; i <= n; i++) {
        mp[v[i]].push_back(i);
    }

    for (auto [x, t] : mp) {
        int m = t.size();
        int idx = 0;
        int cur = 1;
        while (idx < m) {
            int cnt = 1;
            while (idx < m - 1 && t[idx] + 1 == t[idx + 1]) {
                cnt++;
                idx++;
            }
            cur = max(cnt, cur);
            idx++;
        }
        ans = min(ans, x * (n - cur));
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