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
    
string s;

void solve ()
{   
    cin >> s;
    vector <vector <ll> > v(600 + 1, vector <ll> (600 + 1, 0));
    ll x = 300, y = 300;
    v[x][y] = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'U') {
            y++;
        }else if (s[i] == 'D') {
            y--;
        }else if (s[i] == 'L') {
            x--;
        }else {
            x++;
        }
        if (v[x][y] == 1 || v[x - 1][y] + v[x + 1][y] + v[x][y - 1] + v[x][y + 1] > 1) {
            cout << "BUG" << '\n';
            return;
        }
        v[x][y] = 1;
    }
    cout << "OK" << '\n';
}   
 
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}