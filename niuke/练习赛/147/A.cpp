#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<string, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll a, b; cin >> a >> b;
    if (b == 0) b = a;
    for (int i = 1; i <= a; i++) {
        if (i == b) cout << -a - 10 << ' ';
        else cout << 1 << ' ';
    }
    cout << '\n';
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