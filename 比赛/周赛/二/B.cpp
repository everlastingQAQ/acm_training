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
    
ll n, k;

void solve ()
{   
    cin >> n >> k;
    vector <vector <char> > v(n + 1, vector <char> (n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    ll t = n / k;
    vector <vector <char> > ans(t + 1, vector <char> (t + 1));
    
    ll x = 1, y = 1;
    for (int i = 1; i <= t; i++) {
        y = 1;
        for (int j = 1; j <= t; j++) {
            ans[i][j] = v[x][y];
            y += k;
            
        }
        x += k;
    } 

    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= t; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
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