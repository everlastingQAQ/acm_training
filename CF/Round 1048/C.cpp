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
    
ll k, x;

void solve ()
{
    cin >> k >> x;
    ll y = 2 * (1LL << k) - x;
    vector <ll> v;
    while (x != (1LL << k)) {
        if (x < y) {
            y -= x; x *= 2;
            v.push_back(1);
        }else {
            x -= y; y *= 2;
            v.push_back(2);
        }
    }
    cout << v.size() << '\n';
    reverse(v.begin(), v.end());    
    for (auto x : v) {
        cout << x << ' ';
    }
    cout << '\n';
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