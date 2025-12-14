#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
    
ll n, q;

void solve ()
{
    cin >> n >> q;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    while (q--) {
        ll k, x;
        cin >> k >> x;
        ll pos = lower_bound(v.begin() + 1, v.end(), x) - v.begin() - 1;
        if (pos >= k) {
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