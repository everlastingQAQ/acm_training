#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <array <int, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    sort(v.begin() + 1, v.end(), [] (auto a, auto b) {
        if (a[1] != b[1]) return a[1] < b[1];
        else return a[0] > b[0];
    });
    int ans = 0;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i][0] < cur) continue;
        ans++;
        cur = v[i][1];
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