#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;

    vector <pair<ll, ll> > v(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i].fi;
        v[i].se = i;
    }

    sort(v.begin() + 1, v.end(), [] (const pair<ll, ll> &a1, const pair<ll, ll> &b1) {
        return a1.fi < b1.fi;
    });

    double ans = 0;
    double t = 0;
    for (int i = 1; i <= n; i++) {
        t += v[i].fi;
        cout << v[i].se << ' ';
        if (i == n) {
            continue;
        }
        ans += t;
    }

    ans /= n;
    cout << '\n';
    cout << fixed << setprecision(2) << ans << '\n';

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