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
    ll n; cin >> n;
    vector <ll> ans;
    ll t = 10;
    for (int i = 1; i <= 17; i++) {
        if (n % (t + 1) == 0) {
            ans.push_back(n / (t + 1));
        }
        t *= 10;
    }
    ranges::reverse(ans);
    cout << ans.size() << '\n';
    if (ans.size() == 0) return;
    for (ll x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
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