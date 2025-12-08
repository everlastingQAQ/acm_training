#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll t;

void solve ()
{
    cin >> t;
    ll u;
    for (int i = 0; i < t; i++) {
        cin >> u;
        if (u == 1 || u == 2 || u == 4 || u == 5) {
            cout << "Kato_Shoko" << '\n';
        }else {
            cout << "koishiYun" << '\n';
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