#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k; cin >> n >> k;
    vector <array<int, 3> > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    sort(v.begin(), v.end());

    int cur = k;
    for (int i = 0; i < n; i++) {
        if (cur < v[i][0]) break;
        else if (cur > v[i][1]) continue;
        cur = max(cur, v[i][2]);
    }

    cout << cur << '\n';
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