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
const ll inf = LLONG_MAX;

ll n;

void solve ()
{
    cin >> n;
    vector <pi> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
    }

    mt19937_64 rng(random_device{}());

    for (int i = 0; i < 100; i++) {
        ll p = 0, q = 0;
        while (p == q) {
            p = rng() % n;
            q = rng() % n;
        }
        ll a = v[p].se - v[q].se;
        ll b = v[q].fi - v[p].fi;
        ll c = v[p].fi * v[q].se - v[q].fi * v[p].se;
        ll cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a * v[j].fi + b * v[j].se + c == 0) {
                cnt++;
            }
        }
        if (cnt * 2 > n) {
            cout << "Yes" << '\n';
            cout << a << ' ' << b << ' ' << c << '\n';
            return;
        }
    }
    cout << "No" << '\n';
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