#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 m, c, qq;
    cin >> m >> c >> qq;
    vector <i64> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    unordered_map <i64, int> mp;
    
    queue <i64> q;
    q.push(c);
    mp[c] = true;

    while (!q.empty()) {
        i64 x = q.front();
        q.pop();
        for (int i = 0; i < m; i++) {
            i64 t = x - v[i];
            if (t < 0) continue;
            if (t % m != i) continue;
            if (mp[t]) continue;
            q.push(t);
            mp[t] = true;
        }
    }

    while (qq--) {
        i64 t;
        cin >> t;
        cout << (mp[t] ? "Yes\n" : "No\n");
    }
}   
    
int main ()
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