#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;
ll dp[20][20];
ll c[25];

void solve1 ()
{
    cin >> n;

    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = 1;
            }else if (j == 0) {
                dp[i][j] = dp[i - 1][j + 1];
            }else {
                dp[i][j] = dp[i - 1][j + 1] + dp[i][j - 1];
            }
        }
    }

    cout << dp[n][0] << '\n';
}

void solve2 ()
{
    cin >> n;

    c[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            c[i] += c[j] * c[i - j - 1];
        }
    }

    cout << c[n] << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while (_--) {
        //sovle1();
        solve2();
    }
    return 0;
}