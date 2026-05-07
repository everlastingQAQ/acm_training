#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

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

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> ind(n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ind[u]++;
        ind[v]++;
    }
 
    int ans = 0;
    unordered_set <int> st;
    unordered_map <int, int> mp;
    for (int i = 1; i <= n; i ++) {
        st.insert(ind[i]);
        mp[ind[i]]++;
    }

    for (auto x : st) {
        for (auto y : st) {
            if (y == x) continue;
            int c1 = mp[x] % mod;
            int c2 = mp[y] % mod;
            int s = (((x ^ y) % mod * (x | y) % mod) % mod * (x & y) % mod) % mod;
            int res = c1 * c2 % mod * s % mod;
            ans = (ans + res) % mod; 
        }
    }
 
    ans = ans * qpow(2, mod - 2) % mod;
    cout << ans << '\n';
} 

int32_t main ()
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