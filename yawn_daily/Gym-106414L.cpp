#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int qpow (int a, int b)
{
    if (a < 0 || b < 0) return 0;
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve ()
{
    int n;
    cin >> n;
    vector <array <int, 3> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    sort(v.begin() + 1, v.end());
    int ans = 0;
    int t = 0;
    int pre = 1;
    for (int i = 1; i <= n; i++) {
        int cur = 1;
        int j = i;
        if (v[j][0] > t) {
            break;
        }
        bool ok = false;
        while (j <= n && v[j][0] == t) {
            if (v[j][1] == 0) {
                j++;
                continue;
            }
            cur = cur * (v[j][2] - v[j][1]) % mod * qpow(v[j][2], mod - 2) % mod;
            j++;
            ok = true;
        }
        pre = pre * (1 - cur + mod) % mod;
        i = j - 1;
        if (!ok) break;
        ans = (ans + pre) % mod;
        t++;
    }
    cout << ans << '\n';
}

int32_t main ()
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