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
string s;

void solve ()
{
    cin >> n >> s;
    ll cnt_1 = 0;
    ll cnt_0 = 0;
    ll mx_1 = 0;
    ll mx_0 = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt_1++;
        }else {
            cnt_0++;
        }
    }

    ll l = 0, r = 0;
    
    while (r < n) {
        while (r < n && s[r] == '1') {
            r++;
        }
        mx_1 = max(mx_1, r - l);
        l = r;
        while (r < n && s[r] == '0') {
            r++;
        }
        mx_0 = max(mx_0, r - l);
        l = r;
    }

    //cout << mx_1 << ' ' << mx_0 << '\n';

    ll ans = min(cnt_0 + (cnt_1 - mx_1) * 2, cnt_1 + (cnt_0 - mx_0) * 2);

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