#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    map <int, int> mp;
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]]++;
        mx = max(mx, v[i]);
    }
    int mex = 0;
    while (mp[mex]) {
        mex++;
    }
    int ans = (1 + mex) * mex / 2 + (n - mex - 1) * mex + mx * n;
    if (mx == mex - 1) ans++;
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