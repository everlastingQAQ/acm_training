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

void solve ()
{
    ll n; cin >> n;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector <ll> d(n + 1);
    ll mx = 0;
    ll ans = 0;
    ll pos = 0;
    for (int i = 1; i < n; i++) {
        if (i == 1) d[i] = abs(v[2] - v[1]);
        else d[i] = abs(v[i] - v[i - 1]) + abs(v[i + 1] - v[i]) - abs(v[i + 1] - v[i - 1]);
        if (d[i] > mx) {
            mx = max(mx, d[i]);
            pos = i;
        }
        // cout << d[i] << ' ';
    }
    d[n] = abs(v[n] - v[n - 1]);
    // cout << d[n] << '\n';
    if (d[n] > mx) {
        mx = max(mx, d[n]);
        pos = n;
    }
    // cout << pos << ' ' << mx << '\n';
    v.erase(v.begin() + pos);
    // cout << v[pos + 1] << '\n';
    for (int i = 2; i < n; i++) {
        ans += abs(v[i] - v[i - 1]);
        // cout << v[i] << ' ';
    }

    cout << ans << '\n';
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