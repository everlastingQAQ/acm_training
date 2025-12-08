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
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    sort(v.begin() + 1, v.end(), [] (auto &a1, auto &a2) {
        return a1 > a2;
    });

    ll ans = sum;
    ll t = 0;
    ll u = 0;
    ll r = n;

    for (int i = 2; i <= n; i++) {
        u += r - i + 1;
        t++;
        if (v[i] <= t) {
            break;
        }
        while (v[r] <= t) {
            r--;
        }
        if (r <= i) {
            break;
        }
    }

    cout << sum - u << '\n';
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