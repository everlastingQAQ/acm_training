#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, x; cin >> n >> x;
    vector <array<int, 3> > v(n);
    int sum = 0;
    bool found = false;
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        if (v[i][1] >= 2) sum += (v[i][1] - 1) * v[i][0];
        if (v[i][1] * v[i][0] > v[i][2]) found = true;
    }

    if (sum >= x) {
        cout << 0 << '\n';
        return;
    }

    if (!found) {
        cout << -1 << '\n';
        return;
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        int cur = v[i][1] * v[i][0] - v[i][2];
        mx = max(mx, cur);
    }

    int lft = x - sum;

    if (lft % mx == 0) {
        cout << lft / mx << '\n';
    }else {
        cout << lft / mx + 1 << '\n';
    }
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