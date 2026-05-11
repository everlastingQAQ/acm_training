#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        cnt[t]++;
    }

    vector <int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + cnt[i];
    }

    for (int i = n; i >= 1; i--) {
        int res = pre[min(n, 4 * i - 1)] - cnt[i];
        if (i * 2 <= n) res -= cnt[i * 2];
        if (i * 3 <= n) res -= cnt[i * 3];
        if (res <= k) {
            cout << i << '\n';
            return;
        }
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