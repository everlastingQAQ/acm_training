#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void init() 
{

}

void solve ()
{
    int a, b; cin >> a >> b;
    int m = gcd(a, b);
    if (a + b > m && a + m > b && b + m > a) {
        cout << "Yes" << '\n';
    }else {
        cout << "No" << '\n';
    }
}   

signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}