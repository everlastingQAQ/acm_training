#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
const ll inf = LLONG_MAX;

ll n, k;

void solve ()
{
    string s1, s2;
    cin >> s1 >> s2;

    if (s1 == "Lynx") {
        cout << "Yes" << '\n';
    }else if (s1 == "Serval") {
        if (s2 == "Lynx") {
            cout << "No" << '\n';
        }else {
            cout << "Yes" << '\n';
        }
    }else if (s1 == "Ocelot") {
        if (s2 == "Ocelot") {
            cout << "Yes" << '\n';
        }else {
            cout << "No" << '\n';
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