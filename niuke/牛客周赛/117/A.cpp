#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll a, b;

void solve ()
{
    cin >> a >> b;
    if (a == 1 && b == 1) {
        cout << "LU" << '\n';
    }else if (a == 1 && b == 2) {
        cout << "LD" << '\n';
    }else if (a == 2 && b == 1) {
        cout << "RU" << '\n';
    }else if (a == 2 && b == 2) {
        cout << "RD" << '\n';
    }

    return;
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