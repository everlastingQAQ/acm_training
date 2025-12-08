#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, char>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ll n, m;

void solve ()
{
    cin >> n;
    vector <pi> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
    }
    cin >> m;
    
    if (m == 1) {
        char c;
        cin >> c;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (v[i].se == c) {
                ans += v[i].fi;
            }
        }
        cout << ans << '\n';
        return;
    }

    ll ans = 0;
    string s;
    cin >> s;
    if (s[0] == s[1]) {
        for (int i = 0; i < n; i++) {
            if (v[i].se == s[0]) {
                ans += v[i].fi - 1;
            }
        }
        cout << ans << '\n';
    }else {
        for (int i = 0; i < n - 1; i++) {
            if (v[i].se == s[0] && v[i + 1].se == s[1]) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
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