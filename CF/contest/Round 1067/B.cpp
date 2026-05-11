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
    cin >> n;
    vector <ll> v(2 * n + 1);
    map <ll, ll> mp;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }

    ll a = 0, b = 0, c = 0;
    for (auto [x, y] : mp) {
        if (y & 1) {
            a++;
        }else {
            if (y % 4 == 2) {
                b++;
            }else {
                c++;
            }
        }
    }

    if (a != 0 || !(c & 1)) {
        cout << a + 2 * (b + c) << '\n';
    }else {
        cout << a + 2 * (b + c) - 2 << '\n'; 
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