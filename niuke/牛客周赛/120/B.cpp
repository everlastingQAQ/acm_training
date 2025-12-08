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
 
ll l, r;

void solve ()
{   
    cin >> l >> r;
    if (l % 3 == 0) {
        ll cnt = r - l;
        ll t = cnt / 3;
        if (cnt % 3 == 0) {
            cout << t << ' ' << t << ' ' << t + 1 << '\n';
        }else if (cnt % 3 == 1) {
            cout << t + 1 << ' ' << t << ' ' << t + 1 << '\n';
        }else {
            cout << t + 1 << ' ' << t + 1 << ' ' << t + 1 << '\n'; 
        }
    }else if (l % 3 == 1) {
        ll cnt = r - l;
        ll t = cnt / 3;
        if (cnt % 3 == 0) {
            cout << t + 1 << ' ' << t << ' ' << t << '\n';
        }else if (cnt % 3 == 1) {
            cout << t + 1 << ' ' << t + 1 << ' ' << t << '\n';
        }else {
            cout << t + 1 << ' ' << t + 1 << ' ' << t + 1 << '\n'; 
        }
    }else if (l % 3 == 2) {
        ll cnt = r - l;
        ll t = cnt / 3;
        if (cnt % 3 == 0) {
            cout << t << ' ' << t + 1 << ' ' << t << '\n';
        }else if (cnt % 3 == 1) {
            cout << t << ' ' << t + 1 << ' ' << t + 1 << '\n';
        }else {
            cout << t + 1 << ' ' << t + 1 << ' ' << t + 1 << '\n'; 
        }
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