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
    vector <vector<ll> > v(n + 1, vector <ll> (m + 1, 0));
    vector <vector<ll> > sum(n + 1, vector <ll> (m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            sum[i][j] += v[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    ll r = 2;
    while (1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                
            }
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