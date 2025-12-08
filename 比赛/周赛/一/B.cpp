#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 1e9 + 7;

ll n, p, h, r;
map <pair<ll, ll>, bool> vis;

void solve ()
{   
    cin >> n >> p >> h >> r;
    vector <ll> d(n + 1, 0);
    while (r--) {
        ll a, b;
        cin >> a >> b;
        ll mx = max(a, b);
        ll mn = min(a, b);
        if (vis[{mn, mx}]) continue;
        vis[{mn, mx}] = true;
        d[mn + 1]--;
        d[mx]++;
    }

    vector <ll> v(n + 1, h);
    for (int i = 1; i <= n; i++) {
        v[i] = v[i - 1] + d[i];
        cout << v[i] << '\n';
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