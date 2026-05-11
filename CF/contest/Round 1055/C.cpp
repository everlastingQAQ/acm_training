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
    
ll n, q;

void solve ()
{
    cin >> n >> q;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    v[0] = -1;

    vector <ll> a(n + 1);
    vector <ll> c(n + 1);
    for (int i = 1; i <= n; i++) {
        if (v[i] == 1) {
            a[i] = a[i - 1];
        }else {
            a[i] = a[i - 1] + 1;
        }
        if (v[i] == v[i - 1]) {
            c[i] = c[i - 1] + 1;
        }else {
            c[i] = c[i - 1];
        }
    }

    for (int i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        if ((r - l + 1) % 3 != 0 || (a[r] - a[l - 1]) % 3 != 0) {
            cout << -1 << '\n';
            continue;
        }
        if (c[r] - c[l] == 0) {
            cout << (r - l + 1) / 3 + 1 << '\n';
        }else {
            cout << (r - l + 1) / 3 << '\n';
        }
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