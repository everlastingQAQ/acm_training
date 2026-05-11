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
string x;

void solve ()
{
    cin >> n;
    ll mx = 1;
    ll mn = 1;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] > v[mx]) {
            mx = i;
        }
        if (v[i] < v[mn]) {
            mn = i;
        }
    }
    cin >> x;
    x = ' ' + x;

    if (x[1] == '1' || x[n] == '1' || x[mn] == '1' || x[mx] == '1') {
        cout << -1 << '\n';
        return;
    }

    cout << 5 << '\n';
    cout << 1 << ' ' << mn << '\n';
    cout << 1 << ' ' << mx << '\n';
    cout << mn << ' ' << n << '\n'; 
    cout << mx << ' ' << n << '\n';
    cout << min(mn, mx) << ' ' << max(mn, mx) << '\n';
    
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