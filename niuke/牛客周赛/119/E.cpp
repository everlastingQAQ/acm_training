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
    vector <ll> a;
    vector <ll> b;
    vector <ll> v(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll p, q;
        cin >> p >> q;
        v[i] = p;
        if (q == 1) {
            a.push_back(p);
        }else if (q == 2) {
            b.push_back(p);
        }else {
            b.push_back(p);
            ans++;
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(v.begin(), v.end());

    for (auto x : b) {
        ll t = lower_bound(v.begin(), v.end(), 2 * x) - v.begin() - 1;
        ans += t;
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            ll r = lower_bound(v.begin() + j + 1, v.end(), v[i] + v[j]) - v.begin();
            ans += max(r - j - 1, 0LL);
        }
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