#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, k;

void solve ()
{
    cin >> n >> k;

    vector <ll> v(n + 1);
    vector <ll> sum(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    sort(v.begin() + 1, v.end());

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + v[i];
    }

    ll ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = max(sum[n - (k - i)] - sum[2 * i], ans);
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