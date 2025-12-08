#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, s;

void solve ()
{
    cin >> n >> s;
    vector <ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll i = 0, j = 0;
    ll ans = 1e5 + 1, sum = 0;

    while (1) {
        if (sum >= s) {
            ans = min(i - j, ans);
            sum -= v[j];
            j++;
        }else {
            if (i == n) break;
            sum += v[i];
            i++;
        }
    }

    if (ans == 1e5 + 1) {
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
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}