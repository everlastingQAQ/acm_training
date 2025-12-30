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
    ll n, q; cin >> n >> q;
    vector <ll> v(n + 1);
    vector<vector<ll>> st1(n + 1, vector<ll>(35));
    vector<vector<ll>> st2(n + 1, vector<ll>(35));
    for (int i = 1; i <= n; i++) cin >> v[i], st1[i][0] = v[i], st2[i][0] = i;

    for (int j = 1; j <= 30; j++) {
        for (int i = 1; i <= n; i++) {
            ll t = st1[i][j - 1];
            st1[i][j] = st1[t][j - 1];
            st2[i][j] = st2[i][j - 1] + st2[t][j - 1];
        }
    }

    while (q--) {
        ll t, b; cin >> t >> b;
        ll sum = 0;
        for (int i = 0; i <= 30; i++) {
            if (t >> i & 1) {
                sum += st2[b][i];
                b = st1[b][i];
            }
        }
        cout << sum << '\n';
    }
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