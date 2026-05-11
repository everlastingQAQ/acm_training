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

void solve ()
{
    ll n;
    cin >> n;
    vector <ll> a(n + 1);
    vector <ll> b(n + 1);
    ll x = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        x ^= a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        x ^= b[i];
    }

    ll t = 0;

    if (!x) {
        cout << "Tie" << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] ^ b[i]) {
            t = i;
        }
    }

    cout << (t & 1 ? "Ajisai" : "Mai") << '\n';

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