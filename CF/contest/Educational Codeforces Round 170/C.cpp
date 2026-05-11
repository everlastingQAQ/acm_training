#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end());

    int l = 1, r = 1;
    int ans = 0;
    while (r <= n) {
        bool ok = false;
        while (r <= n && v[r] - v[l] < k && (!ok || (v[r] == v[r - 1] || v[r] == v[r - 1] + 1))) {
            r++;
            ok = true;
        }
        ans = max(ans, r - l);
        if (v[r] != v[r - 1] && v[r] != v[r - 1] + 1) {
            l = r;
            continue;
        }
        int x = v[l];
        while (l <= min(r, n) && v[l] == x) {
            l++;
        }
    }
    cout << ans << '\n';
} 

int main ()
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