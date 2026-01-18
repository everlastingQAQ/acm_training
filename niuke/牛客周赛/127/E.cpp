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
    string s; cin >> s;
    int n = s.size();
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') cnt++;
    }

    if (n == 1) {
        cout << qpow(2, cnt) << '\n';
        return;
    }

    char a = s[0], b = s[n - 1];

    if (a != '?' && b != '?') {
        if ((a ^ b) == !(n & 1)) cout << qpow(2, cnt) << '\n';
        else cout << 0 << '\n';
    }else {
        cout << qpow(2, cnt - 1) << '\n';
    }
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