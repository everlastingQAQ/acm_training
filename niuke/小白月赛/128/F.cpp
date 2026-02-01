#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6;
const int mod = 1000000007;

int f[N], g[N];

int qpow (int a, int b)
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int C (int n, int m)
{
    return f[n] * g[m] % mod * g[n - m] % mod;
}

void init ()
{
    f[0] = 1, g[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % mod;
        g[i] = qpow(f[i], mod - 2) % mod;
    }
}

void solve ()
{
    int n, m; cin >> n >> m;
    unordered_map <int, int> mp;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i], mp[v[i]]++;

    ranges::sort(v | views::drop(1));
    v.erase(unique(v.begin() + 1, v.end()), v.end());
    int t = v.size();
    int cnt = 0;

    for (int i = 1; i < t; i++) {
        if (mp[v[i]] % v[i] != 0) {
            cout << 0 << '\n';
            return;
        }
        cnt += mp[v[i]] / v[i];
    }
    if (cnt > m) {
        cout << 0 << '\n';
        return;
    }

    int ans = 1;
    int temp = 1;
    for (int i = 0; i < cnt; i++) {
        ans = (ans * (m - i)) % mod;
    }
    ans = (ans * g[cnt]) % mod;

    for (int i = 1; i < t; i++) {
        int count = mp[v[i]] / v[i];
        int cur = C(cnt, count) * f[mp[v[i]]] % mod * qpow(qpow(f[v[i]], count), mod - 2) % mod;
        ans = (ans * cur) % mod;
        cnt -= count;
    }
    cout << ans << '\n';
}   
    
int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
} 