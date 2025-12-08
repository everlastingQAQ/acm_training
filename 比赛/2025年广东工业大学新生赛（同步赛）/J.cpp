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
    vector <ll> v(n + 1, 0);
    vector <ll> d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        d[i] = v[i] - v[i - 1];
    }
    ll sum = 0;
    for (int i = 2; i <= n; i++) {
        sum += d[i];
    }
    sort(d.begin() + 2, d.end(), greater<ll>());
    for (int i = 2; i <= n; i++) {
        cout << sum << ' ';
        sum -= d[i];
    }
    cout << sum << '\n';
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