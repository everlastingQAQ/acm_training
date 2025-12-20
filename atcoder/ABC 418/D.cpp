#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

void solve ()
{   
    ll n; string s; cin >> n >> s; s = " " + s;
    vector <pi> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            dp[i].fi = dp[i - 1].se;
            dp[i].se = dp[i - 1].fi + 1;
        }else {
            dp[i].fi = dp[i - 1].fi + 1;
            dp[i].se = dp[i - 1].se;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i].fi;
    }
    cout << ans << '\n';
}

void solvee ()
{
    ll n; string s; cin >> n >> s; s = " " + s;
    ll cnt[2] = {1, 0};
    ll ans = 0;
    ll pre = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') pre ^= 1;
        ans += cnt[pre];
        cnt[pre]++;
    }
    cout << ans << '\n';
}
 
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while (_--) {
        solvee();
    }
    return 0;
}