#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, m;

void solve ()
{
    cin >> n >> m;
    if (n == m) {
        cout << 0 << endl;
        return;
    }

    ll mx = max(n, m);
    bool p = false;
    bool q = false;
    for (ll i = 2; i <= mx * 2; i *= 2) {
        ll x = n % i;
        ll y = m % i;
        if (x > y) {
            p = true;
        }else if (x < y) {
            q = true;
        }
        if (p && q) {
            break;
        }
    }

    if (p && q) {
        cout << 2 << endl;
    }else if (p && !q || q && !p) {
        cout << 1 << endl;
    }else if (!p && !q) {
        cout << 0 << endl;
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

