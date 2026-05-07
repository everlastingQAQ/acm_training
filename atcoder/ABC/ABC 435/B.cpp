#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, char>;

#define fi first
#define se second

const int N = 3e5;
const double eps = 1e-5;
const ll mod = 998244353;

void solve ()
{
    ll n; cin >> n;
    vector <ll> v(n + 1);
    vector <ll> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        s[i] = s[i - 1] + v[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ll sum = s[j] - s[i - 1];
            for (int k = i; k <= j; k++) {
                if (sum % v[k] == 0) {
                    ans--;
                    break;
                }
            }
            ans++;   
        }
    }

    cout << ans << '\n';
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