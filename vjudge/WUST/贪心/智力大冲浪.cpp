#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll m, n;

void solve ()
{
    cin >> m >> n;
    vector <pair<ll, ll> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].fi;
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i].se;
    }

    sort(v.begin() + 1, v.end(), [](const pair<ll, ll> &a1, const pair<ll, ll> &b1) {
        return a1.se > b1.se;
    });
    
    vector <bool> a(n + 1, false);
    ll t = 0;
    for (int i = 1; i <= n; i++) {
        while (v[i].fi > 0 && a[v[i].fi] == true) {
            v[i].fi--;
        }
        if (v[i].fi == 0) {
            t += v[i].se;
            continue;
        }
        a[v[i].fi] = true;
    }

    if (m - t < 0) {
        cout << 0 << '\n';
    }else {
        cout << m - t << '\n';
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