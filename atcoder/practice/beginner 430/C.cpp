#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, a, b;
string s;

void solve ()
{
    cin >> n >> a >> b >> s;

    ll cnt_a = 0, cnt_b = 0;
    ll ans = 0;
    for (int i = 0, j = 0, k = 0; i < n; i++) {
        while (cnt_a < a && j < n) {
            if (s[j++] == 'a') {
                cnt_a++;
            }
        }
        while (cnt_b < b && k < n) {
            if (s[k++] == 'b') {
                cnt_b++;
            }
        }

        if (cnt_a >= a) {
            ll t;
            if (cnt_b >= b) {
                t = k;
            }else {
                t = n - 1;
            }
            if (j <= t - 1) {
                ans += t - j;
            }
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