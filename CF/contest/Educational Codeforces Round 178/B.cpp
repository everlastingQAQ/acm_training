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
    for (int i = n; i >= 1; i--) {
        cin >> v[i];
    }

    vector <ll> s(n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + v[i];
    }

    vector <ll> mx(n + 2);
    for (int i = n; i >= 1; i--) {
        mx[i] = max(mx[i + 1], v[i]);
    }

    vector <ll> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ans[i] = max(s[i - 1] + v[i], s[i - 1] + mx[i]);
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
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