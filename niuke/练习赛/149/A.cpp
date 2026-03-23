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
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (v[i] <= v[i - 1]) {
            ans += v[i - 1] - v[i] + 1;
            v[i] = v[i - 1] + 1;
        }
    }
    cout << ans << '\n';
}   
    
int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 