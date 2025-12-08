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
 
ll n, m;

void solve ()
{   
    cin >> n >> m;
    if (n == 1 || m == 1) {
        cout << 1 << '\n';
        return;
    }else if (n == 2 || m == 2) {
        if (n == 2) {
            cout << (m + 1) / 2 << '\n';
        }else {
            cout << (n + 1) / 2 << '\n';
        }
        return;
    }else if (n == 3 && m == 3) {
        cout << 8 << '\n';
        return;
    }else {
        cout << n * m << '\n';
        return;
    }
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