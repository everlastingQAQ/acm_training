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
    vector <ll> a(13), b(13);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;

    ll ans = 0;
    for (int i = 0; i < 13; i++) {
       ans += max(a[i] + b[i] - 4, 0LL); 
    }
    cout << ans << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}   