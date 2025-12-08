#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, q;

void solve ()
{
    cin >> n >> q;

    map<pair<ll, ll>, ll> mp;

    ll a;
    for (int i = 0; i < q; i++) {
        cin >> a;
        ll q, w, e;
        if (a == 1) {
            cin >> q >> w >> e;
            mp[{q, w}] = e;
        }else if (a == 2) {
            cin >> q >> w;
            cout << mp[{q, w}] << endl;
        }
    }
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}