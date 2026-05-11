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
    ll l, a, b; cin >> l >> a >> b;
    ll cnt = 0;
    ll ans = 0;
    while (cnt <= b) {
        a += b;
        if (a >= l) {
            cnt++;
            while (a >= l) {
                a -= l;
            }
        }
        ans = max(a, ans);
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