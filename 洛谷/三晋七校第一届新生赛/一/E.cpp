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

    ll a, b;
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
        if (i == 0) {
            a = v[i].fi;
            b = v[i].se;
        }
    }

    sort(v.begin(), v.end(), [] (auto &a1, auto &b1) {
        if (a1.fi != b1.fi) {
            return a1.fi > b1.fi;
        }else {
            return a1.se < b1.se;
        }
    });

    ll gold = n * 0.1;
    ll silver = n * 0.3;
    ll bronze = n * 0.6;

    for (int i = 0; i < n; i++) {
        if (v[i].fi == a && v[i].se == b) {
            if (i + 1 <= gold) {
                cout << "gold" << '\n';
            }else if (i + 1 > gold && i + 1 <= silver) {
                cout << "silver" << '\n';
            }else if (i + 1 > silver && i + 1 <= bronze) {
                cout << "bronze" << '\n';
            }else {
                cout << "iron" << '\n';
            }
            return;
        }
    }

    return;
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