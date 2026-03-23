#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n + 1);
    map <int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(v.begin() + 1, v.end());
    map <int, bool> vis;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[v[i]]) continue;
        vis[v[i]] = true;
        vis[k - v[i]] = true;
        cnt += abs(mp[k - v[i]] - mp[v[i]]);
    }
    cout << (n - cnt) / 2 << '\n';
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
