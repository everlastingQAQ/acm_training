#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
    
string s;

void solve ()
{   
    cin >> s;
    ll n = s.size();
    s = " " + s;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        v[i] = v[i - 1] + (s[i] == '1' ? 1 : -1);
    }

    map <ll, ll> mp;
    ll ans = 0;
    mp[0] = 1;

    for (int i = 1; i <= n; i++) {
        ans = (ans + ((n - i + 1) % mod) * (mp[v[i]] % mod)) % mod;
        mp[v[i]] = (mp[v[i]] + i + 1) % mod;
    }

    cout << ans << '\n';
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