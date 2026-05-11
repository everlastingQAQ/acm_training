#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;
 
ll n;

void solve ()
{
    cin >> n;
    map <ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        mp[t]++;
    }    
    vector <pi> v;
    for (auto [x, y] : mp) {
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), [] (auto a1, auto b1) {
        return a1.se > b1.se;
    });

    ll ans1 = 0, ans2 = 0;
    ll cnt = 0;
    for (auto [x, y] : v) {
        if (cnt & 1) {
            ans1 += y * floor(1.0 * x / 2);
            ans2 += y * ceil(1.0 * x / 2);
        }else {
            ans1 += y * ceil(1.0 * x / 2);
            ans2 += y * floor(1.0 * x / 2);
        }
        cnt += x;
    }
    cout << ans1 << ' ' << ans2 << '\n';
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