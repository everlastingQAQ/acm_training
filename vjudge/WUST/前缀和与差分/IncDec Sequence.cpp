#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    vector <ll> d(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        d[i] = v[i] - v[i - 1];
    }

    ll ans1 = 0;
    ll ans2 = 0;
    for (int i = 2; i <= n; i++) {
        if (d[i] > 0) {
            ans1 += d[i];
        }else {
            ans2 -= d[i];
        }
    }

    cout << max(ans1, ans2) << '\n' << abs(ans1 - ans2) + 1 << '\n';

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