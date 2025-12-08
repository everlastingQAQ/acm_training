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
 
ll n, q;

void solve ()
{   
    cin >> n;
    if (n == 1) {
        cout << "aba" << '\n';
    }else if (n == 2) {
        cout <<  "aabaa" << '\n';
    }else if (n == 3) {
        cout << "aaabaaa" << '\n';
    }else if (n == 4) {
        cout << "aaaabaaaa" << '\n';
    }else if (n == 5) {
        cout << "aaaaabaaaaa" << '\n';
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