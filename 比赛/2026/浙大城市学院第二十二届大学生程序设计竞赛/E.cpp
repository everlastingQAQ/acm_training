#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    string s; cin >> s;
    s = ' ' + s;
    ll ans = 0;
    for (int i = 1; i < s.size() - 2; i++) {
        if (s[i] == 'h' && s[i + 1] == 'y' && s[i + 2] == 'w') {
            // cout << i << '\n';
            ans ^= i;
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