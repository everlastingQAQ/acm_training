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
 
ll x, y, z;

void solve ()
{
    cin >> x >> y >> z;

    for (int i = 31; i >= 0; i--) {
        ll a = (x >> i) & 1;
        ll b = (y >> i) & 1;
        ll c = (z >> i) & 1;
        if (a + b + c == 2) {
            cout << "No" << '\n';
            return;
        } 
    }
    cout << "Yes" << '\n';
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