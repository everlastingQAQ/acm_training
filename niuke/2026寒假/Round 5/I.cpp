#include <bits/stdc++.h>
using namespace std;
#define int long long
    
void solve ()
{
    int n, m, h;
    cin >> n >> m >> h;
    vector <array <int, 2> > v(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    auto check = [&] (int md) -> bool {
        vector <int> d1(n + 5);
        for (int i = 1; i <= md; i++) {
            auto [idx, val] = v[i];
            
            int l1 = max(1LL, idx - val + 1);
            int r1 = idx - 1;
            int a = idx - val - l1;
            int d = -1;
            d1[l1] += a;
            d1[l1 + 1] += d - a;
            d1[r1 + 1] -= (r1 - l1 + 1) * d + a;
            d1[r1 + 2] += a + (r1 - l1) * d;

            int l2 = idx, r2 = min(n, idx + val - 1);
            a = -val, d = 1;
            d1[l2] += a;
            d1[l2 + 1] += d - a;
            d1[r2 + 1] -= (r2 - l2 + 1) * d + a;
            d1[r2 + 2] += a + (r2 - l2) * d;
        }

        for (int i = 1; i <= n; i++) {
            d1[i] += d1[i - 1];
        }

        for (int i = 1; i <= n; i++) {
            d1[i] += d1[i - 1];
            if (d1[i] + h < 0) return false;
        }

        return true;
    };

    int l = 0, r = m;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }

    if (l == m + 1) {
        cout << "No\n"; 
    }else {
        cout << "Yes\n" << l << '\n';
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/