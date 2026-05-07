#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, x;
    cin >> n >> x;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int l = 1, r = 1;
    i64 sum = 0;
    int ans = 1e8;
    int al = 1, ar = 1;
    while (r <= n) {
        sum += v[r];
        while (l <= min(r, n) && sum >= x) {
            if (r - l + 1 < ans) {
                ans = r - l + 1;
                al = l;
                ar = r;
            }
            sum -= v[l];
            l++;
        }
        r++;
    }
    cout << al << ' ' << ar << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}