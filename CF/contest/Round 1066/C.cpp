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

ll n, k, q;    

void solve ()
{
    cin >> n >> k >> q;
    vector <ll> v(n + 1);

    vector <ll> a(n + 1, 0), b(n + 1, 0);

    while (q--) {
        ll c, l, r;
        cin >> c >> l >> r;
        for (ll i = l; i <= r; i++) {
            if (c == 1) {
                a[i] = 1;
            }else {
                b[i] = 1;
            }
        }

        for (ll i = 1; i <= n; i++) {
            if (a[i] == 1 && b[i] == 1) {
                v[i] = k + 1;
            }else if (b[i] == 1) {
                v[i] = i % k;
            }else {
                v[i] = k;
            }
        }

    }   

    for (ll i = 1; i <= n; i++) {
        cout << v[i] << ' ';
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