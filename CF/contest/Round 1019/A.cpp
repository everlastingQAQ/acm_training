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
 
ll n;

void solve ()
{
    cin >> n;
    map <ll, bool> mp;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll t; cin >> t;
        if (mp[t] != true) {
            ans++;
            mp[t] = true;
        }
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