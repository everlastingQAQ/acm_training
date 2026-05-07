#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 1e9 + 7;

ll n, h;

void solve ()
{
    cin >> n >> h;
    ll a = h, b = h;
    ll pre_t = 0;
    bool found = false;
    for (int i = 0; i < n; i++) {
        ll t, l, u;
        cin >> t >> l >> u;

        ll dt = t - pre_t;
        pre_t = t;
        a = a - dt, b = b + dt;

        if (found == false && (a > u || b < l)) {
            cout << "No" << '\n';
            found = true;
        }

        a = max({l, a, 1LL});
        b = min(u, b);

    }
    
    if (!found) {
        cout << "Yes" << '\n';
    }
    
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