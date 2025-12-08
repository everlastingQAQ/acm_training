#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll q;

void solve ()
{
    map <string, ll> mp;
    cin >> q;

    ll a, b;
    string s;
    while (q--) {
        cin >> a >> s;
        if (a == 1) {
            cin >> b;
            mp[s] += b;
        }else if (a == 2) {
            mp.erase(s);
        }else if (a == 3) {
            cout << mp[s] << '\n';
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