#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, k;

void solve ()
{
    cin >> n >> k;

    vector <pair<ll, ll> > v;
    v.reserve(2 * n);
    ll a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.emplace_back(a - k, +1);
        v.emplace_back(a + k, -1);
    }
        
    sort(v.begin(), v.end(), [] (auto &a1, auto &b1) {
        if (a1.fi != b1.fi) {
            return a1.fi < b1.fi;
        }else {
            return a1.se > b1.se;
        }
    });

    ll ans = 0;
    ll t = 0;
    for (auto x : v) {
        t += x.se;
        ans = max(t, ans);
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
