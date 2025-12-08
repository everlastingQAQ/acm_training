#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ll n, m;

void solve ()
{
    cin >> n >> m;
    vector <ll> v(n);
    unordered_map <ll, unordered_map<ll, ll > > mp;

    auto get_len = [&] (const ll &a) {
        ll length = 0;
        ll t = a;
        while (t > 0) {
            t /= 10;
            length++;
        }
        return length;
    };

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[get_len(v[i])][v[i] % m]++;
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll t = v[i] % m;
        for (int j = 1; j <= 12; j++) {
            t = (t * 10) % m;
            ans += mp[j][(m - t) % m];
        }
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
        solve();
    }
    return 0;
}