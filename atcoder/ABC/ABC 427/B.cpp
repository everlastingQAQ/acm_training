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
    v[0] = 1;
    v[1] = 1;
    for (int i = 2; i <= n; i++) {
        ll t = v[i - 1];
        ll sum = 0;
        while (t > 0) {
            sum += t % 10;
            t /= 10;
        }
        v[i] = v[i - 1] + sum;
    }
    cout << v[n] << '\n';
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