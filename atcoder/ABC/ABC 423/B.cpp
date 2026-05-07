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

ll n;

void solve ()
{
    cin >> n;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    ll l = 1;
    for (int i = 1; i <= n; i++) {
        if (v[i] == 1) {
            l = i;
            break;
        }
    }
    ll r = n;
    for (int i = n; i >= 1; i--) {
        if (v[i] == 1) {
            r = i;
            break;
        }
    }
    if (r == n && l == 1 && v[l] == 0 && v[r] == 0) {
        cout << 0 << '\n';
    }else {
        cout << max(0LL, r - l) << '\n';
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