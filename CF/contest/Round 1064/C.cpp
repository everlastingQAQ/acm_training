#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;

void solve ()
{
    cin >> n;
    vector <ll> v(n + 1);
    vector <ll> a(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (i == 1) {
            continue;
        }
        a[i] = max(v[i], v[i - 1]);
        ans += a[i];
    }
    a[1] = max(v[1], v[n]);
    ans += a[1];

    ll mx = *max_element(a.begin() + 1, a.end());

    ans -= mx;

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