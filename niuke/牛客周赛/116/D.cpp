#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;

    vector <pair<ll, ll> > v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
    }

    sort(v.begin(), v.end(), [] (const pair<ll, ll> &a1, const pair<ll, ll> &b1) {
        if (a1.fi != b1.fi) {
            return a1.fi < b1.fi;
        }else {
            return a1.se < b1.se;
        }
    });

    vector <ll> a(n);

    for (int i = 0; i < n; i++) {
        a[i] = v[i].se;
    }

    sort(v.begin(), v.end(), [] (const pair<ll, ll> &a1, const pair<ll, ll> &b1) {
        return a1.se < b1.se;
    });

    for (int i = 0; i < n; i++) {
        if (a[i] != v[i].se) {
            cout << "No" << '\n';
            return;
        }
    }

    if (v[0].se < v[n - 1].fi || v[0].fi > v[n - 1].se) {
        cout << "No" << '\n';
        return;
    }

    cout << "Yes" << '\n';
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