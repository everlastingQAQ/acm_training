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
    ll n; cin >> n;
    vector <ll> v(n + 1), s(n + 1), prez(n + 5), pref(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        s[i] = s[i - 1] + v[i];
        if (v[i] >= 0 && i != 1) {
            prez[i] = prez[i - 1] + v[i];
            pref[i] = pref[i - 1];
        }
        else if (v[i] < 0 && i != 1){
            prez[i] = prez[i - 1];
            pref[i] = pref[i - 1] + v[i];
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            ans = -(s[n] - s[1]);
            continue;
        }else {
            ll res = -(s[n] - s[i]) + v[1] + prez[i - 1] - pref[i - 1];
            ans = max(ans, res);
        }
    }
    cout << ans << "\n";
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