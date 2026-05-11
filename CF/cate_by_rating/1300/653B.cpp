#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <array <string, 2> > v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    int len = 1;
    int ans = 0;
    queue <string> q;
    q.push("a");
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        if (s.size() == n) {
            ans++;
            continue;
        }
        for (auto [x, y] : v) {
            if (s[0] == y[0]) {
                string ss = s;
                ss.erase(ss.begin());
                q.push(x + ss);
            }
        }
    }
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