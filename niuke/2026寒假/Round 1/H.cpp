#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

int qpow (int a, int b)//a的b次方
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1);
    vector <vector <int> > a(n + 1);

    auto cal = [&] (int x, int pos) -> void {
        for (int i = 0; i <= 30; i++) {
            if ((x >> i & 1) == 1) a[pos].push_back(i);
        }
    };

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        cal(v[i], i);
    }

    vector <int> pre(n + 1, 1);
    pre[0] = 1;
    unordered_map <int, int> premp;

    for (int i = 1; i <= n; i++) {
        int cur = pre[i - 1];
        for (auto x : a[i]) {
            cur = max(cur, premp[x] + 1);
            premp[x] = i;
        }
        pre[i] = cur;
    }

    vector <int> dp(n + 1);
    vector <int> s(n + 1);
    dp[0] = 1, s[0] = 1;

    for (int i = 1; i <= n; i++) {
        int l = (pre[i] >= 2 ? s[pre[i] - 2] : 0);
        dp[i] = (s[i - 1] - l + mod) % mod;
        s[i] = (s[i - 1] + dp[i]) % mod;
    }

    cout << dp[n] << '\n';
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/