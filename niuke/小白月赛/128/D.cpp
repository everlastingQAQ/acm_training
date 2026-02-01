#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m; cin >> n >> m;
    vector <int> v(n + 1), s(n + 1, 0), a(n + 1);
    unordered_map <int, int> mp;
    for (int i = 1; i <= n; i++) cin >> v[i], a[i] = v[i];
    ranges::sort(v | views::drop(1));
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + v[i];
    vector <int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int t = m - v[i];
        int pos = upper_bound(v.begin() + 1, v.end(), t) - v.begin() - 1;
        if (pos >= i) {
            ans[i] += (pos - 1) * v[i];
            ans[i] -= s[n] - s[pos];
        }else if (pos < i) {
            ans[i] += pos * v[i];
            ans[i] -= s[n] - s[pos] - v[i];
        }
        mp[v[i]] = ans[i];
    }
    for (int i = 1; i <= n; i++) cout << mp[a[i]] << " \n"[i == n];
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