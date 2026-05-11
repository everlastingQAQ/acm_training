#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i - 1;
        int t = max(v[i], v[n] - v[i]);
        while (l < r) {
            while (l < r && v[l] + v[r] <= t) {
                l++;
            }
            ans += r - l;
            r--;
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