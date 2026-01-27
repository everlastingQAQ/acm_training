#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int mod = 998244353;

int dp[500010][2][2];

void solvee ()
{
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    memset(dp, 0, sizeof dp);
   
    if (s[1] == '1') dp[1][0][1] = 1;
    else if (s[1] == '0') dp[1][0][0] = 1;
    else {
        dp[1][0][0] = 1;
        dp[1][0][1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        if (s[i] == '0') {
            dp[i][0][0] = (dp[i - 1][1][0] + dp[i - 1][0][1]) % mod;
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][1][1]) % mod;
        }else if (s[i] == '1') {
            dp[i][0][1] = (dp[i - 1][0][0] + dp[i - 1][1][1]) % mod;
            dp[i][1][1] = (dp[i - 1][1][0] + dp[i - 1][0][1]) % mod;
        }else {
            dp[i][0][0] = (dp[i - 1][1][0] + dp[i - 1][0][1]) % mod;
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][1][1]) % mod;
            dp[i][0][1] = (dp[i - 1][0][0] + dp[i - 1][1][1]) % mod;
            dp[i][1][1] = (dp[i - 1][1][0] + dp[i - 1][0][1]) % mod;
        }
    }
    cout << (dp[n][0][0] + dp[n][0][1]) % mod << '\n';
}

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
        solvee();
    }
    return 0;
}