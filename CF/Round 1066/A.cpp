#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ll n; 

void solve ()
{
    cin >> n;
    vector <ll> v(n + 1);
    vector <ll> a(n + 1, 0);
    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        a[v[i]]++;
        mx = max(mx, v[i]);
    }
    ll ans = 0;
    for (int i = 0; i <= mx; i++) {
        if (a[i] < i) {
            ans += a[i];
        }else if (a[i] > i) {
            ans += a[i] - i;
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