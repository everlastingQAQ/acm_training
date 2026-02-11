#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n);
    map <int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    ranges::sort(v);
    v.erase(unique(v.begin(), v.end()), v.end());
    int m = v.size();
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int cur = mp[v[i]];
        cnt += mp[v[i]] - 1;
        if (5 * cnt >= 4 * (n - 1)) {
            ans += v[i] * cur;
        }
        cnt++;
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/