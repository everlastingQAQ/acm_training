#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
 
ll m, n;

void solve ()
{
    cin >> n;
    ll sum = (1 + n) * n / 2;

    if (sum & 1) {
        cout << 0 << '\n';
        return;
    }

    vector <ll> f(sum + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= i; j--) {
            f[j] += f[j - i];
        }
    }

    cout << *max_element(f.begin() + 1, f.end()) / 2 << '\n';
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