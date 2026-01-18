#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    vector <int> v(n);
    map <int, int> mp;
    for (int &x : v) cin >> x, mp[x]++;
    ranges::sort(v);
    int mx = v[n - 1];

    if (mp[0] == 0 || (mp[0] >= 2 && mp[1] == 0)) {
        cout << "No" << '\n';
        return;
    }

    cout << "Yes" << '\n';
}   
    
signed main ()
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