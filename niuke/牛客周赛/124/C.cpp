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
    ll n, m; cin >> n >> m;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    sort(v.begin() + 1, v.end());

    vector <array<ll, 3> > a;
    
    ll l = 1, r = 1;
    while (r <= n) {
        while (r < n && v[r + 1] - v[r] == 1) {
            r++;
        }        
        if (r == n && v[r] - v[r - 1] == 1) {
            a.push_back({v[l], v[r], v[r] - v[l] + 1});
            break;
        }
        a.push_back({v[l], v[r], v[r] - v[l] + 1});
        r++;
        l = r;
    }

    ll ans = 0;
    for (int i = 0; i < a.size(); i++) {
        ans = max(ans, a[i][2] + 1);
        if (i != a.size() - 1 && a[i][1] == a[i + 1][0] - 2) {
            ans = max(ans, a[i][2] + a[i + 1][2] + 1);
        }
    }
    
    if (ans >= m) {
        cout << "YES" << '\n';
    }else {
        cout << "NO" << '\n';
    }
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