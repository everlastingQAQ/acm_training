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
    
ll n, k;

void solve ()
{   
    cin >> n >> k;
    vector <ll> v(n + 1);
    ll cnt = 0;
    map <ll, ll> mpp;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mpp[v[i]]++;
    }

    for (auto &[x, y] : mpp) {
        if (y % k != 0) {
            cout << 0 << '\n';
            return;
        }else {
            y /= k;
        }
    }

    map <ll, ll> mp;
    ll l = 1, r = 1;
    ll ans = 0;

    while (r <= n) {
        mp[v[r]]++;
        while (mp[v[r]] > mpp[v[r]]) {
            mp[v[l]]--;
            l++;
        }
        ans += r - l + 1;
        r++;
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