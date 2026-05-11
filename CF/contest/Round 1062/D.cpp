#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e18 + 1;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;

void solve ()
{
    cin >> n;
    vector <ll> v(n);
    ll x;
    cin >> x;
    v[0] = x;
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        x = gcd(v[i], x);
    }

    ll ans = 2;
    bool found = false;
    while (!found) {
        if (gcd(ans, x) == 1) {
            found = true;
            break;
        }else {
            ans++;
        }
    }

    cout << ans << endl;
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