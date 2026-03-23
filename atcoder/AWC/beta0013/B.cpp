#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    map <array <int, 2> , int> mp;
    vector <array <int, 2> > v(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> v[i][0] >> v[i][1];
        mp[{v[i][0], v[i][1]}] = true;
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (mp[{v[i][0], v[i][1]}] && mp[{v[i][1], v[i][0]}]) ans++;
    }

    cout << ans / 2 << '\n';
    
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