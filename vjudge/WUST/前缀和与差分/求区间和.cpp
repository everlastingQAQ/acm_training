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
    vector <ll> v(n + 1);
    vector <ll> sum(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum[i] = sum[i - 1] + v[i];
    }

    ll m;
    cin >> m;

    while (m--) {
        ll a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << '\n';
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