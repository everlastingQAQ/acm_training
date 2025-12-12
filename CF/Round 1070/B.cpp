#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
    
ll n;
string s;

void solve ()
{
    cin >> n >> s;
    s = s + s;
    ll t = 0;
    ll ans = 0;

    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '0') {
            t++;
            ans = max(ans, t);
        }else {
            t = 0;
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