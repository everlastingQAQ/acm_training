#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

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
    ll mx1 = 0;
    ll mx2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
        ll cnt = 0;
        for (int j = 2; j <= v[i].fi; j++) {
            if (v[i].se % j == 0) {
                cnt++;
            }
        }
        if (cnt % 2 == 0) {
            cout << "Yes" << '\n';
        }else {
            cout << "No" << '\n';
        }
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