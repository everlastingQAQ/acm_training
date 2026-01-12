#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void solve ()
{
    int x; cin >> x;
    int cnt = 0;
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            cnt++;
            x /= i;
        }
    }
    if (x > 1) cnt++;
    cout << (cnt & 1 ? "kou" : "yukari") << '\n';
}   

signed main ()
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