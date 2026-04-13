#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector <i64> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }

    vector <i64> pre(n + 1), suf(n + 2);
    
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        if (cnt <= m && v[i] >= a[cnt]) {    
            cnt++;
            pre[i]++;
        }
    }
    cnt = m;
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1];
        if (cnt >= 1 && v[i] >= a[cnt]) {    
            cnt--;
            suf[i]++;
        }
    }

    i64 ans = 1e18;
    for (int i = 0; i <= n; i++) {
        i64 cur = pre[i] + suf[i + 1];
        if (cur == m) {
            ans = 0;
            break;
        }else if (cur == m - 1) {
            ans = min(ans, a[pre[i] + 1]);
        }
    }

    cout << (ans == 1e18 ? -1 : ans) << '\n';
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