#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;
    vector <bool> v(2 * n + 1, false);
    vector <ll> ans(2 * n + 1);

    ll t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> t;
            ans[i + j] = t;
            v[t] = true;
        }
    }

    for (int i = 1; i <= 2 * n; i++) {
        if (v[i] == false) {
            ans[1] = i;
            break;
        }
    }

    for (int i = 1; i <= 2 * n; i++) {
        cout << ans[i] << ' ';
    }

    cout << endl;
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