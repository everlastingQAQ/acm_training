#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, x;
    cin >> n >> x;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end());
    int l = 1, r = n;
    int ans = 0;
    while (l <= r) {
        if (l == r) {
            ans++;
            break;
        }
        if (v[r] + v[l] > x) {
            ans++;
            r--;
        }else {
            ans++;
            r--;
            l++;
        }
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