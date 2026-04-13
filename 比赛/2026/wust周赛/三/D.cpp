#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int N = 2e5 + 10;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

void solve ()
{
    ll n, k; cin >> n >> k;
    vector <ll> v(n);
    for (ll &x : v) cin >> x;
    vector <vector <ll> > a(N);

    for (ll x : v) {
        ll t = x;
        ll cur = 0;
        while (t > 0) {
            a[t].push_back(cur++);
            t /= 2;
        }
    }

    ll ans = 1e15;

    for (int i = 0; i < N; i++) {
        if (a[i].size() < k) continue;
        ranges::sort(a[i]);
        ans = min(accumulate(a[i].begin(), a[i].begin() + k, 0LL), ans);
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