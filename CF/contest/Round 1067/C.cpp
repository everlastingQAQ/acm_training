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
    
ll n, k;

void solve ()
{
    cin >> n >> k;
    vector <ll> a(n + 1);
    vector <ll> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector <ll> lft(n + 3, 0);
    vector <ll> rgt(n + 3, 0);
    for (int i = 1; i <= n; i++) {
        lft[i] = max(lft[i - 1] + a[i], a[i]);
    }
    for (int i = n; i >= 1; i--) {
        rgt[i] = max(rgt[i + 1] + a[i], a[i]);
    }

    ll ans = LLONG_MIN;
    if (!(k & 1)) {
        for (int i = 1; i <= n; i++) {
            ans = max(ans, lft[i] + rgt[i] - a[i]);
        }
    }else {
        for (int i = 1; i <= n; i++) {
            ans = max(ans, lft[i] + rgt[i] - a[i] + b[i]);
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