#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector <i64> val(n + 1);
    vector <i64> cnt(32);
    for (int i = 31; i >= 0; i--) {
        for (int j = 1; j <= n; j++) {
            if (v[j] >> i & 1) cnt[i]++;
        }
        for (int j = 1; j <= n; j++) {
            if (v[j] >> i & 1) {
                val[j] += (n - cnt[i]) * (1LL << i);
            }else {
                val[j] += cnt[i] * (1LL << i);
            }
        }
    }

    i64 ans = ranges::max(val);
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