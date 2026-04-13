#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;

    vector <ll> a(n);
    vector <ll> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll mx = 0;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] > mx) {
            mx =  b[i];
            ans = a[i];
        }
    }

    cout << ans << '\n';
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