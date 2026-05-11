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
    vector <bool> v(n + 1, false);

    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        v[t] = true;
    }

    for (int i = 0; i <= n; i++) {
        if (!v[i]) {
            cout << i << '\n';
            return;
        }
    }

    cout << n + 1 << '\n';
    return;
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