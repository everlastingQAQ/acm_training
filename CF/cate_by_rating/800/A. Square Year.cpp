#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
string s;

void solve ()
{
    cin >> s;
    ll a = stoll(s);
    
    ll x = sqrt(a) - 1;

    if (x * x == a) {
        if (x % 2 == 0) {
            cout << x / 2 << ' ' << x / 2 << '\n';
        }else {
            cout << x / 2 + 1 << ' ' << x / 2 << '\n';
        }
        return;
    }
    if ((x + 1) * (x + 1) == a) {
        if ((x + 1) % 2 == 0) {
            cout << (x + 1) / 2 << ' ' << (x + 1) / 2 << '\n';
        }else {
            cout << (x + 1) / 2 + 1 << ' ' << (x + 1) / 2 << '\n';
        }
        return;
    }
    if ((x + 2) * (x + 2) == a) {
        if ((x + 2) % 2 == 0) {
            cout << (x + 2) / 2 << ' ' << (x + 2) / 2 << '\n';
        }else {
            cout << (x + 2) / 2 + 1 << ' ' << (x + 2) / 2 << '\n';
        }
        return;
    }
    cout << -1 << '\n';
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