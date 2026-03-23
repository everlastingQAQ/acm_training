#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    sort(v.begin() + 1, v.end());

    int l = 1, r = accumulate(v.begin() + 1, v.end(), 0LL);

    auto check = [&] (int md) -> bool {
        
    };

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }

    cout << l << '\n';
    
}   
    
signed main ()
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