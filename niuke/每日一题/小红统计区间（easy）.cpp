#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    i64 k;
    cin >> k;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    int l = 1, r = 1;
    i64 ans = 0;
    i64 cur = 0;
    while (r <= n) {
        cur += v[r];
        if (cur < k) {
            r++;
            continue;
        }
        while (l < r && cur - v[l] >= k) {
            cur -= v[l];
            l++;
        }
        ans += l;
        r++;
    }

    cout << ans << '\n';
}   
    
int main ()
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