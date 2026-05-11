#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 998244353;

i64 qpow (i64 a, i64 b)
{
    i64 res = 1;
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
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector <i64> cnt2(n + 1, 0), s2(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cnt2[i] = cnt2[i - 1] + (v[i] == 2);
        s2[i] = qpow(2, cnt2[i]);
    }

    vector <i64> cnt1(n + 1, 0), s1(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cnt1[i] = cnt1[i - 1] + (v[i] == 1);
        s1[i] = s1[i - 1];
        if (v[i] == 1) {
            s1[i] = (s1[i] + qpow(qpow(2, cnt2[i]), mod - 2)) % mod;
        }
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] == 3) {
            ans = (ans + s2[i] * s1[i] % mod - cnt1[i] + mod) % mod;
        }
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