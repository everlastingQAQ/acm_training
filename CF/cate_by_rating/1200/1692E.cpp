#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, s;
    cin >> n >> s;
    vector <int> v(n + 2);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    if (sum < s) {
        cout << -1 << '\n';
        return;
    }else if (sum == s) {
        cout << 0 << '\n';
        return;
    }

    vector <int> suf(n + 2);
    vector <int> a(n + 2);
    int cur = n + 1;
    for (int i = n + 1; i >= 0; i--) {
        suf[i] = cur;
        if (v[i] == 1) {
            cur = i;
        }
    }

    int idx = 0;
    cur = 1;
    for (int i = 1; i <= n; i++) {
        a[i] = suf[idx] - cur + 1;
        idx = suf[idx];
        cur = idx + 1;
    }
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }

    vector <int> pre(n + 2);
    vector <int> b(n + 2);
    cur = 0;
    for (int i = 0; i <= n + 1; i++) {
        pre[i] = cur;
        if (v[i] == 1) {
            cur = i;
        }
    }

    idx = n + 1;
    cur = n;
    for (int i = 1; i <= n; i++) {
        b[i] = cur - pre[idx] + 1;
        idx = pre[idx];
        cur = idx - 1;
    }
    for (int i = 1; i <= n; i++) {
        b[i] += b[i - 1];
    }

    int ans = 1e9;
    int t = sum - s;
    for (int i = 0; i <= t; i++) {
        ans = min(a[i] + b[t - i], ans);
    }
    cout << ans << '\n';
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