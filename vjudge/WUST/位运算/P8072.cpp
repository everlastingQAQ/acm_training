#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll k;

void solve ()
{
    cin >> k;

    ll a = 1;
    while (a < k) {
        a *= 2;
    }

    if (a == k) {
        cout << a << ' ' << 0 << endl;
        return;
    }else {
        cout << a << ' ';
    }

    ll b = 0;

    while (k != 0) {
        a /= 2;
        k %= a;
        b++;
    }

    cout << b << endl;

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

