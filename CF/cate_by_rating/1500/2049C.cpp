#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector <int> ans(n + 1);
    if (n & 1) {
        for (int i = 1; i < n; i++) {
            ans[i] = !(i & 1);
        }
        ans[n] = 2;
        if (ans[x] == ans[y]) {
            if (x == n - 1 || x == 1) {
                swap(ans[x], ans[n]);
            }else {
                ans[x] = 2;
            }
        }
    }else {
        for (int i = 1; i <= n; i++) {
            ans[i] = !(i & 1);
        }
        if (ans[x] == ans[y]) {
            ans[x] = 2;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int main ()
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