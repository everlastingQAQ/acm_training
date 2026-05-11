#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector <int> vis(n + 10);
    int mex = 0;
    for (int i = 1; i < k; i++) {
        vis[v[i]] = true;
        while (vis[mex]) {
            mex++;
        }
    }
    if (mex > v[k]) {
        cout << k << ' ' << k << '\n';
        return;
    }

    for (int i = k + 1; i <= n; i++) {
        vis[v[i]] = true;
        while (vis[mex]) {
            mex++;
        }
        if (mex > v[k]) {
            cout << k << ' ' << i << '\n';
            return;
        }
    }

    cout << -1 << ' ' << -1 << '\n';
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