#include <bits/stdc++.h>
using namespace std;
using ld = long double;

#define fi first
#define se second
#define int long long

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void init() 
{

}

void solve ()
{
    int n, a, b; cin >> n >> a >> b;
    int mx = lcm(a, b);
    while (n--) {
        int t; cin >> t;
        int x = 0, y = t / b;
        if (y * b < t) y++;
        int mn = y * b - t;
        if (mn == 0) {
            cout << x << ' ' << y << '\n';
            continue;
        }
        for (int i = 1; i <= mx / a; i++) {
            int temp = (t - a * i) / b;
            if (temp * b < t - a * i) temp++;
            if (temp * b + i * a - t < mn && temp >= 0) {
                x = i, y = temp;
                mn = temp * b + i * a - t;
                if (mn == 0) break;
            }
        }
        cout << x << ' ' << y << '\n';
    }
}   

signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}