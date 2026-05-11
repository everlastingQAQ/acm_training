#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

void solve ()
{
    ll n, x, y;  
    cin >> n >> x >> y;
    string s;
    cin >> s;
    ll cnt_4 = 0;
    for (char c : s) {
        if (c == '4') {
            cnt_4++;
        }
    }

    ll cnt_8 = n - cnt_4;
    if (abs(x) > n || abs(y) > n) {
        cout << "No" << '\n';
        return;
    }

    if (abs(x) >= n - (cnt_4 - 1) || abs(y) >= n - (cnt_4 - 1)) {
        if (abs(x) + abs(y) > 2 * cnt_8 + cnt_4) {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';

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