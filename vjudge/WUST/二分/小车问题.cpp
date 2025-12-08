#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
double s, a, b;

void solve ()
{
    cin >> s >> a >> b;

    double x = (2 * a * s) / (3 * a + b);
    double ans = (x / a + (s - x) / b);
    
    cout << fixed << setprecision(6) << ans << '\n';
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