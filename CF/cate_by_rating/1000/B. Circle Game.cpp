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
    
ll n;

void solve ()
{
    cin >> n;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    if (n & 1) {
        cout << "Mike" << '\n';
        return;
    }

    ll mn = 1e9 + 10;
    ll pos = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] < mn) {
            mn = v[i];
            pos = i;
        }
    }

    if (pos & 1) {
        cout << "Joe" << '\n';
    }else {
        cout << "Mike" << '\n';
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