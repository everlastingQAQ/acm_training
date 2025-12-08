#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, m;

void solve ()
{
    cin >> n >> m;
    vector <vector<ll> > v(n, vector <ll> (2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> v[i][j];
        }
    }

    vector <ll> a(n);
    for (int i = 1; i <= m; i++) {
        
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