#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll a, x, y;

void solve ()
{
    cin >> a >> x >> y;
    ll t = abs(x - y) / 2; 
    
    if (a > min(x, y) && a < max(x, y)){
        cout << "NO" << '\n';
    }else {
        cout << "YES" << '\n';
    }
    
    return;
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
