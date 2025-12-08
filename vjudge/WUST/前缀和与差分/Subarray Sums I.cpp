#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, x;

void solve ()
{
    cin >> n >> x;

    ll sum = 0, t;
    ll ans = 0;
    map <ll, ll> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> t;
        sum += t;
        ans += mp[sum - x];
        mp[sum]++;
    }

    cout << ans << '\n';
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