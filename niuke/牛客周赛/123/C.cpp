#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, char>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

void solve ()
{
    ll n; cin >> n;
    map <pi, bool> mp;
    vector <vector <ll> > v(n + 1);
    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        ll a; char c; cin >> a >> c;
        mx = max(mx, a);
        if (!mp[{a, c}]) {
            mp[{a, c}] = true;
            v[a].push_back(i);
        }
    }

    vector <pair<ll, ll> > ans;
    ll cnt = 0;
    for (int i = 1; i <= mx; i++) {
        for (int j = 0; j + 1 < v[i].size(); j += 2) {
            cnt++;
            ans.push_back({v[i][j], v[i][j + 1]});
        }
    }

    cout << cnt * 2 << '\n';
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
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