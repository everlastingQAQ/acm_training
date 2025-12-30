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
    ll n, l; cin >> n >> l;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    ld lft = ranges::min(v | views::drop(1));
    ld rgt = ranges::max(v | views::drop(1));

    auto check = [&] (ld x) -> bool {
        vector <ld> s(n + 1, 0.0);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + (v[i] - x);
        ld mn = 0.0;

        for (int i = l; i <= n; i++) {
            mn = min(mn, s[i - l]);
            if (s[i] - mn >= 0) return true;
        }

        return false;
    };

    ll q = 100;
    while (q--) {
        ld mid = 1.0 * (lft + rgt) / 2;
        if (check(mid)) {
            lft = mid;
        }else {
            rgt = mid;
        }
    }

    cout << fixed << setprecision(9) << lft << '\n';
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