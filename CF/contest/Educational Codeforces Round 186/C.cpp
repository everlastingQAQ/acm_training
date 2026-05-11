#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll n; cin >> n;
    vector <ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector <ll> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector <ll> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];

    vector <ll> v1(n + 1);
    vector <ll> v2(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j] >= b[i]) v1[(j - i + 2 * n) % n + 1] = 1;
            if (c[j] <= b[i]) v2[(j - i + 2 * n) % n + 1] = 1;
        }
    }

    ll cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        if (v1[i] == 0) cnt1++;
        if (v2[i] == 0) cnt2++;
    }

    cout << n * cnt1 * cnt2 << '\n';

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