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

string s;

void solve ()
{
    cin >> s;
    ll l = 0;
    ll r = 0;

    ll ans = 0;
    while (r < s.size()) {
        ll pos1 = l;
        while (l < s.size() && s[l + 1] == s[l]) {
            l++;
        }
        r = l + 1;
        ll pos = l + 1;
        while (r < s.size() && s[r + 1] == s[r]) {
            r++;
        }
        // cout << r << ' ' << l << '\n';
        // cout << s[r] << ' ' << s[l] << '\n'; 
        if (s[r] == s[l] + 1) {
            ans += min({r - l, l - pos1 + 1});
            // cout << ans << '\n';
        }
        r++;
        l = pos;
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