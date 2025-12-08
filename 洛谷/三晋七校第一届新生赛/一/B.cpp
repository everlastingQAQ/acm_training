#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, a, b;

void solve ()
{
    cin >> n >> a >> b;
    vector <ll> v(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    if (b <= a) {
        cout << n * b << '\n';
        return; 
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += min(b, a * (v[i] - v[i - 1]));
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