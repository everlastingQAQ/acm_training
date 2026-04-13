#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
 
string s;

void solve ()
{
    cin >> s;
    ll a = 0, c = 0, m = 0, ac = 0, cm = 0, acm = 0;
    for (auto e : s) {
        if (e == 'a') {
            a++, ac += c, acm += cm;
        }else if (e == 'c') {
            c++, cm += m;
        }else if (e == 'm') {
            m++;
        }else if (e == 'A') {
            a++;
        }else if (e == 'C') {
            c++, ac += a;
        }else if (e == 'M') {
            m++, cm += c, acm += ac;
        }
        cout << acm % mod << ' ';
    }
    cout << '\n';
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