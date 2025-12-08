#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
const ll inf = LLONG_MAX;

ll n, q;

void solve ()
{
    cin >> n >> q;
    ll mn = 1;
    vector <ll> a(n + 1, 1);

    while (q--) {
        ll x, y;
        cin >> x >> y;

        ll sum = 0;
        while (mn <= x) {
            sum += a[mn];
            a[y] += a[mn];
            mn++;
        }
        cout << sum << '\n';
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