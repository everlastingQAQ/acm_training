#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, m, k; cin >> n >> m >> k;
    vector <int> a(n + 2), b(m + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    string s; cin >> s; s = ' ' + s;
    vector <int> rec(k + 1); 
    for (int i = 1; i <= k; i++) {
        if (s[i] == 'L') {
            rec[i] = -1;
        }else {
            rec[i] = 1;
        }
    }

    // for (int i = 1; i <= k; i++) {
    //     cout << rec[i] << " \n"[i == k];
    // }

    ranges::sort(a | views::drop(1) | views::take(n));
    ranges::sort(b | views::drop(1) | views::take(m));
    b[0] = -1e11;
    b[m + 1] = 1e11;

    vector <array<int, 2> > v1(n + 1);
    vector <array<int, 2> > v2(n + 1);
    for (int i = 1; i <= n; i++) {
        int l = ranges::upper_bound(b | views::drop(1), a[i]) - b.begin() - 1;
        int r = ranges::upper_bound(b | views::drop(1), a[i]) - b.begin();
        // if (l < 1) v1[i][0] = 1e11;
        // else v1[i][0] = a[i] - b[l];
        // if (r > n) v2[i][0] = 1e11;
        // else v2[i][0] = b[r] - a[i];
        v1[i][0] = a[i] - b[l], v2[i][0] = b[r] - a[i];
        v1[i][1] = i, v2[i][1] = i;
        // cout << l << ' ' << r << ' ' << i << '\n';
    }

    ranges::sort(v1 | views::drop(1), [] (auto a1, auto b1) { 
        return a1[0] < b1[0]; 
    });
    ranges::sort(v2 | views::drop(1), [] (auto a1, auto b1) {
        return a1[0] < b1[0]; 
    });

    // for (int i = 1; i <= n; i++) {
    //     cout << v1[i][0] << ' ' << v1[i][1] << '\n';
    // }
    // for (int i = 1; i <= n; i++) {
    //     cout << v2[i][0] << ' ' << v2[i][1] << '\n';
    // }

    map <int, int> mp;

    int cur = 0;
    int l = 1, r = 1;
    int ans = n;
    for (int i = 1; i <= k; i++) {
        cur += rec[i];
        // cout << cur << '\n';
        if (cur < 0) {
            int t = -cur;
            // cout << v1[l][0] << ' ' << t << '\n';
            while (l <= n && v1[l][0] <= t) {
                if (mp[v1[l][1]] == 0) {
                    ans--;
                    mp[v1[l][1]] = 1;
                }
                l++;
                // cout << 999 << '\n';
            }
        }else if (cur > 0) {
            while (r <= n && v2[r][0] <= cur) {
                if (mp[v2[r][1]] == 0) {
                    ans--;
                    mp[v2[r][1]] = 1;
                }
                r++;
            }
        }
        cout << ans << " \n"[i == k];
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