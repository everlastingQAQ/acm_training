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
    
ll a, b;

void solve ()
{   
    cin >> a >> b;
    if ((a & 1) && (b & 1)) {
        cout << a * b + 1 << '\n';
    }else if (!(a & 1) && !(b & 1)) {
        cout << a * (b / 2) + b / (b / 2) << '\n';
    }else if ((a & 1) && !(b & 1)) {
        if (b % 4 != 0) {
            cout << -1 << '\n';
        }else {
            cout << a * (b / 2) + b / (b / 2) << '\n';
        }
    }else if (!(a & 1) && (b & 1)) {
        cout << -1 << '\n';
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