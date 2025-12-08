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

ll n, k;

void solve ()
{
    cin >> n >> k;
    vector <ll> a(n + 1);
    vector <ll> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());

    ll ans = inf;
    ll j = n;
    for (int i = n - k + 1; i <= n; i++) {
        ans = min(ans, a[i] + b[j]);
        j--;
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