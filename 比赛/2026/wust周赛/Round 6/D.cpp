#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end());
    int xx = v[(n + 1) / 2];

    int ans = 1e8;
    for (int i = 1; i < n; i++) {
        if (v[(n - i + 1) / 2] != xx) {
            ans = min(ans, i);
            break;
        }
    }
    for (int i = 1; i < n; i++) {
        if (v[i + (n - i + 1) / 2] != xx) {
            ans = min(ans, i);
            break;
        }
    }
    cout << (ans == 1e8 ? -1 : ans) << '\n';
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