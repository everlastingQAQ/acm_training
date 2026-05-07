#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll n; cin >> n;
    if (n % 4 != 0) {
        cout << 365 << '\n';
    }else {
        if (n % 100 != 0) {
            cout << 366 << '\n';
        }else {
            if (n % 400 != 0) {
                cout << 365 << '\n';
            }else {
                cout << 366 << '\n';
            }
        }
    } 
}
 
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}