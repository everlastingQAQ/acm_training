#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    i64 s;
    cin >> n >> s;
    vector <i64> v(n + 1), pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end());

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + v[i];
    }

    if (pre[n] >= s) {
        cout << n << '\n';
        return;
    }

    i64 l = 0, r = 2e9;

    auto check = [&] (i64 md) -> bool {
        int pos = upper_bound(v.begin() + 1, v.end(), md) - v.begin();
        i64 sum1 = pre[n] - pre[pos - 1];
        i64 sum2 = (1 + md) * md / 2;
        return sum1 + sum2 < s;
    };

    while (l <= r) {
        i64 mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }

    int pos = upper_bound(v.begin() + 1, v.end(), r) - v.begin();
    i64 add = r - pos + 1;
    cout << n + add + 1 << '\n';
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