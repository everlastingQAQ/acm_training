#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n + 1);
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (i <= k) s1 += v[i];
        if (i > k && i <= 2 * k) s2 += v[i];
    }

    // cout << s1 << ' ' << s2 << '\n';

    int l1 = 1, r1 = k + 1, l2 = k + 1, r2 = 2 * k + 1;
    int c1 = s1, c2 = s2;
    int a1 = l1, a2 = l2;
    int mx = s1 + s2;
    int aa1 = l1;

    while (r2 <= n) {
        c2 += v[r2++] - v[l2++];
        c1 += v[r1++] - v[l1++];
        if (c1 > s1) {
            s1 = c1;
            aa1 = l1;
        }
        if (s1 + c2 > mx) {
            mx = s1 + c2;
            a1 = aa1;
            a2 = l2;
        }
    }

    cout << a1 << ' ' << a2 << '\n';
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