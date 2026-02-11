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

    ranges::sort(v | views::drop(1));

    int l = 1, r = 1;
    int ans = 0;
    while (r <= n) {
        if (v[r] - v[l] <= k) {
            r++;
        }
    }
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