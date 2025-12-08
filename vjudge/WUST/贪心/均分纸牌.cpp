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
    vector <ll> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    double t = 1.0 * sum / n;

    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > t) {
            v[i + 1] += v[i] - t;
            ans++;
        }else if (v[i] < t) {
            v[i + 1] -= t - v[i];
            ans++;
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