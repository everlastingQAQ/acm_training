#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<string, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void init() 
{

}

void solve ()
{
    ll n, k; cin >> n >> k;
    vector <ll> a(n), b(n);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;

    ll ans = 0;
    vector <ll> c(n);
    for (int i = 0; i < n; i++) {
        ans += max(a[i], b[i]);
        c[i] = min(a[i], b[i]);
    }
    ranges::sort(c);

    for (int i = n - 1; i >= n - k + 1; i--) {
        ans += c[i];
    }

    cout << ans + 1 << '\n';
}   

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}