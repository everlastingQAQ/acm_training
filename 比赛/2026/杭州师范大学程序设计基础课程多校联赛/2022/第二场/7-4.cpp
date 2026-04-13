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
    vector <vector<ll> > v(4, vector <ll> (4));
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> v[i][j];
        }
    }

    ll judge = v[1][1] + v[1][2] + v[1][3];
    if (v[2][1] + v[2][2] + v[2][3] != judge || v[3][1] + v[3][2] + v[3][3] != judge) {
        cout << "NO" << '\n';
        return;
    }

    if (v[1][1] + v[2][1] + v[3][1] != judge || v[1][2] + v[2][2] + v[3][2] != judge || v[1][3] + v[2][3] + v[3][3] != judge) {
        cout << "NO" << '\n';
        return;
    }

    if (v[1][1] + v[2][2] + v[3][3] != judge || v[1][3] + v[2][2] + v[3][1] != judge) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
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