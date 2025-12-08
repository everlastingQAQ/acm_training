#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ll c, d;

void solve ()
{
    cin >> c >> d;

    ll ans = 0;
    string s1 = to_string(c);
    string s2 = to_string(d);
    string s3 = to_string(c + d);
    ll mxx = stoll(s1 + s3);
    ll t = 10;
    ll mx, mn;
    bool found = true;

    while (found) {
        mn = c * t + max(c + 1, t / 10);
        mx = c * t + min(c + d, t - 1);
        if (mx >= mxx) {
            mx = mxx;
            found = false;
        }
        ll l = sqrtl(mn - 1);
        ll r = sqrtl(mx);
        ans += max(0LL, r - l);
        t *= 10;
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