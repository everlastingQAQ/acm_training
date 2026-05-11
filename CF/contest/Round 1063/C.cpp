#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector <i64> cnt(2 * n + 1, 1e11);
    vector <i64> pmn(n + 1), pmx(n + 1), qmn(n + 1), qmx(n + 1);
    pmn[1] = a[1];
    pmx[1] = a[1];
    for (int i = 2; i <= n; i++) {
        pmn[i] = min(pmn[i - 1], a[i]);
        pmx[i] = max(pmx[i - 1], a[i]);
    }
    qmn[n] = b[n];
    qmx[n] = b[n];
    for (int i = n - 1; i >= 1; i--) {
        qmn[i] = min(qmn[i + 1], b[i]);
        qmx[i] = max(qmx[i + 1], b[i]);
    }

    vector <i64> v(2 * n + 1, 1e11);
    for (int i = 1; i <= n; i++) {
        i64 mn = min(qmn[i], pmn[i]);
        i64 mx = max(qmx[i], pmx[i]);
        v[mn] = min(v[mn], mx);
    }
    i64 cur = 1e11;
    for (int i = 2 * n; i >= 1; i--) {
        cur = min(cur, v[i]);
        cnt[i] = cur;
    }

    i64 ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (cnt[i] == 1e11) continue;
        ans += 2 * n - cnt[i] + 1;
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