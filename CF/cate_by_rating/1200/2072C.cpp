#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, x;
    cin >> n >> x;
    vector <int> ans(n + 1, 0);
    int sum = 0;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if ((x | i) == x) {
            ans[cnt] = i;
            sum |= i;
            cnt++;
        }else break;
    }
    if (sum != x) ans[n] = x;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
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