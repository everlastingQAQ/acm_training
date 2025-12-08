#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, m;

void solve ()
{
    cin >> n >> m;

    vector <ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    ll l = 0, r = m - 1;
    ll ans = v[n - 1];

    while (r < n) {
        ans = min(v[r] - v[l], ans);
        l++;
        r++;
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