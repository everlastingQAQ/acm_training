#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;

void solve ()
{
    cin >> n;
    if (n == 1) {
        cout << "Zhang Win!" << '\n';
        return;
    }else if (n == 0) {
        cout << "Wang Win!" << '\n';
        return;
    }   
    if (n % 2 == 0) {
        cout << "Zhang Win!" << '\n';
    }else {
        cout << "Wang Win!" << '\n';
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