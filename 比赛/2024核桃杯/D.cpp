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
    vector <ll> v(n + 1, 0);
    vector <ll> d(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        d[i] = v[i] - v[i - 1];
    }

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }else if (n == 2) {
        if (v[2] - v[1] >= 0) {
            cout << v[2] - v[1] << '\n';
        }else {
            cout << 0 << '\n';
        }
        return;
    }

    ll ans = *max_element(d.begin() + 2, d.end());

    if (ans <= 0) {
        cout << 0 << '\n';
    }else {
        cout << ans << '\n';
    }
    
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