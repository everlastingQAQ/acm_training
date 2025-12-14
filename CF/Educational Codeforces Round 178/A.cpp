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
    
ll a, b, c;

void solve ()
{
    cin >> a >> b >> c;
    ll sum = a + b + c;
    ll t = sum / 3;
    if (c < t || b > t || a > t || sum % 3 != 0) {
        cout << "No" << '\n';
    }else {
        cout << "Yes" << '\n';
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