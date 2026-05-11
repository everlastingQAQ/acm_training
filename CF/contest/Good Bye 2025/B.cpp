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

void solve ()
{
    string s; cin >> s;
    ll ans = 0;
    if (s[0] == 'u') {
        ans++;
        s[0] = 's';
    }
    if (s[s.size() - 1] == 'u') {
        ans++;
        s[s.size() - 1] = 's';
    }

    ll l = 1, r = 1;
    while (r < s.size() - 1) {
        if (s[r] == 'u') {
            while (s[r] == 'u') {
                r++;
            }
            r--;
            if (r - l + 1 == 1) {
                r++;
                l = r;
                continue;
            }
            // cout << l << ' ' << r << '\n';
            if ((r - l + 1) & 1) {
                ans += (r - l) / 2;
            }else {
                ans += (r - l + 1) / 2;
            }
            r++;
            l = r;
        }else {
            r++;
            l = r;
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