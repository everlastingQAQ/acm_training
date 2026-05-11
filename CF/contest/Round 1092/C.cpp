#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k, p, q;
    cin >> n >> k >> p >> q;
    if (p > q) swap(p, q);
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    } 
    vector <i64> a(n + 1), b(n + 1), mn(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = v[i] % p;
        b[i] = v[i] % q % p;
        mn[i] = min(a[i], b[i]);
    }

    vector <i64> pa(n + 1), pb(n + 1), pmn(n + 1);
    for (int i = 1; i <= n; i++) {
        pa[i] = pa[i - 1] + a[i];
        pb[i] = pb[i - 1] + b[i];
        pmn[i] = pmn[i - 1] + mn[i];
    }
    
    i64 ans = 1e18;
    for (int i = k; i <= n; i++) {
        i64 cur = pmn[i - k] + min(pb[i] - pb[i - k], pa[i] - pa[i - k]) + pmn[n] - pmn[i];
        ans = min(ans, cur);
    }
    
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