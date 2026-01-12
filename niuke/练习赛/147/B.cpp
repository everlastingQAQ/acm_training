#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<string, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void init() 
{

}
    
void solve ()
{
    ll n; cin >> n;
    vector <ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector <ll> a = v;
    ranges::sort(a);
    for (int i = 0; i < n; i++) {
        ll t = sqrtl(a[i] * v[i]);
        if (t * t != a[i] * v[i]) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}   

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}