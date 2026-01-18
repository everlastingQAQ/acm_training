#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int mod = 998244353;

int qpow (int a, int b)//a的b次方
{
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
    int n; cin >> n;
    map <int, int> mp;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i], mp[v[i]]++;

    vector <int> rec(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (mp[i] >= 2) {
            rec[i] = mp[i] * (mp[i] - 1) % mod * qpow(2, mod - 2) % mod;
            mx++;
        }else break;
    }

    vector <int> sum(mx + 1, 1);
    for (int i = 1; i <= mx; i++) {
        sum[i] = sum[i - 1] * rec[i] % mod;
    }

    int ans = 0;
    for (int i = 1; i <= mx; i++) {
        ans = (ans + sum[i]) % mod;
    }

    cout << ans << '\n';
}   
    
signed main ()
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