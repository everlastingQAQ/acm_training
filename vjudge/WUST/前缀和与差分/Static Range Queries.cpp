#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, q;

void solve ()
{
    cin >> n >> q;
    vector <ll> d(1e9, 0);
    
    ll l, r, v;
    for (int i = 0; i < n; i++) {
        cin >> l >> r >> v;
        d[l] += v;
        d[r] -= v;
    }

    vector <ll> a(1e9, 0);

    for (int i = 0; i < 1e9; i++) {
        if (i == 0) {
            a[i] = d[i];
            continue;
        }
        a[i] = a[i - 1] + d[i];
    }

    for (int i = 0; i < 1e9; i++) {
        if (i == 0) {
            a[i] = d[i];
            continue;
        }
        a[i] = a[i - 1] + d[i];
    }

    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << a[r - 1] - a[l - 1] << '\n';
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