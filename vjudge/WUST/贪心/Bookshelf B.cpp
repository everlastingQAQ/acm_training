#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, b;

void solve ()
{
    cin >> n >> b;

    vector <ll> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<ll> ());
    ll ans = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        sum += v[i];
        ans++;
        if (sum >= b) {
            break;
        }
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