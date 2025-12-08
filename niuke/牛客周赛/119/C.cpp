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

ll l, r;

void solve ()
{
    cin >> l >> r;
    ll cnt = 0;
    for (int i = l; i <= min(81LL, r); i++) {
        ll t = i * i;
        string s = to_string(t);
        ll sum = 0;
        for (char x : s) {
            sum += x - '0';
        }
        if (sum == i) {
            cnt++;
        }
    }
    cout << cnt << '\n';
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