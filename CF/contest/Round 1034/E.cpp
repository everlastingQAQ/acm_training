#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    sort(v.begin() + 1, v.end());
    vector <int> cnt(mx + 5, 0);
    for (int i = 1; i <= n; i++) {
        cnt[v[i]]++;
    }

    int t = mx + 1;
    for (int i = 0; i <= mx; i++) {
        if (cnt[i] == 0) {
            t = i;
            break;
        }
    }
    // cout << t << '\n';
    // cout << mx << '\n';
    
    vector <int> pre(mx + 5, 0), suf(mx + 5, 0);
    if (cnt[0]) pre[0] = cnt[0] - 1;
    else pre[0] = 0;
    for (int i = 1; i <= mx; i++) {
        pre[i] = pre[i - 1];
        if (cnt[i] != 0) {
            pre[i] += cnt[i] - 1;
        }
        // cout << pre[i] << " ";
    }
    // cout << '\n';
    suf[mx] = cnt[mx];
    for (int i = mx - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + cnt[i];
    }

    vector <int> diff(n + 10, 0);
    for (int i = 0; i <= t; i++) {
        int l = cnt[i];
        int r;
        if (i >= 1) r = cnt[i] + pre[i - 1] + suf[i + 1];
        else r = cnt[i] + suf[i + 1];
        diff[l] += 1;
        diff[r + 1] -= 1;
    }

    vector <int> ans(n + 5, 0);
    ans[0] = diff[0];
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i - 1] + diff[i];
    }

    for (int i = 0; i <= n; i++) {
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