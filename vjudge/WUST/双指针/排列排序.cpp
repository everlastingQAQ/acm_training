#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
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

    ll ans = 0;
    ll i = 1, j = 1;

    while (i <= n) {
        if (v[i] == i) {
            i++;
            continue;
        }
        j = i;
        ll mx = v[j];
        while (j < mx) {
            j++;
            mx = max(v[j], mx);
        }
        ans += j - i + 1;
        i = j + 1;   
    }
    
    cout << ans << '\n';
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