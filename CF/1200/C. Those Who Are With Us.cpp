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
    
ll n, m;

void solve ()
{   
    cin >> n >> m;
    vector <vector <ll> > v(n + 1, vector <ll> (m + 1));
    ll mx = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            mx = max(mx, v[i][j]);
        }
    }

    ll cntmx = 0;
    vector <ll> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j] == mx) cntmx++, a[i]++, b[j]++;
        } 
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] + b[j] - (v[i][j] == mx) == cntmx) {
                cout << mx - 1 << '\n';
                return;
            }
        }
    }

    cout << mx << '\n';
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