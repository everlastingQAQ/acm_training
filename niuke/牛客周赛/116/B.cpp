#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll a, b, c, d;

void solve ()
{
    cin >> a >> b >> c >> d;

    if (a > c && b < d || a < c && b > d) {
        cout << 'A' << '\n';
    }else if (b < c || a > d) {
        cout << 'B' << '\n';
    }else {
        cout << 'C' << '\n'; 
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