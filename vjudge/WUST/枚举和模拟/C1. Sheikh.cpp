#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, q; cin >> n >> q;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    int x, y; cin >> x >> y;
    vector <int> s(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + v[i];
        pre[i] = pre[i - 1] ^ v[i];
    }

    int al = x, ar = y;
    int len = y - x + 1;
    int t = (s[y] - s[x - 1]) - (pre[y] ^ pre[x - 1]);
    for (int i = x; i <= y; i++) {
        int l = i, r = y;

        auto check = [&] (int md) -> bool {
            return (s[md] - s[i - 1]) - (pre[md] ^ pre[i - 1]) == t;
        };
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) r = mid - 1;
            else l = mid + 1;
        }
        
        if (l >= i && l <= y && check(l)) {
            if (l - i + 1 < len) {
                al = i, ar = l;
                len = ar - al + 1;
            }
        }
    }

    cout << al << ' ' << ar << '\n';
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