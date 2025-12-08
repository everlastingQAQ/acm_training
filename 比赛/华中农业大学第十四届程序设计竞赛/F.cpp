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

ll n;

void solve ()
{
    cin >> n;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    ll cnt = 1;
    map <ll, bool> mp;
    for (int i = 1; i <= n; i++) {
        if (!mp[v[i]]) {
            mp[v[i]] = true;
        }else {
            mp.clear();
            cnt++;
            mp[v[i]] = true;
        }
    }
    cout << cnt << ' ' << n << '\n';
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