    #include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll a, b, x, y;

void solve ()
{
    cin >> a >> b >> x >> y;

    if (a == b) {
        cout << 0 << endl;
        return;
    }else if (a > b) {
        if ((a ^ 1) != b) {
            cout << -1 << endl;
            return;
        }else if (a ^ 1 == b) {
            cout << y << endl;
            return;
        }
    }

    ll ans = 0;
    if (x <= y) {
        ans = (b - a) * x;
    }else {
        if (a % 2 == 0 && b % 2 == 0) {
            ans = (b - a) / 2 * (x + y);
        }else if (a % 2 == 0 && b % 2 == 1) {
            ans = (b - a + 1) / 2 * y + (b - a - 1) / 2 * x;
        }else if (a % 2 == 1 && b % 2 == 0) {
            ans = (b - a + 1) / 2 * x + (b - a - 1) / 2 * y;
        }else if (a % 2 == 1 && b % 2 == 1) {
            ans = (b - a) / 2 * (x + y);
        }
    }

    cout << ans << endl;

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
