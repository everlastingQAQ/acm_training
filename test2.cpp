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

    map <array<ll, 2> , ll> mp1;
    map <array<ll, 2> , ll> mp2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j] >= b[i]) mp1[{(j - i + 2 * n) % n + 1, 1}] = 1;
            if (c[j] <= b[i]) mp2[{1, (j - i + 2 * n) % n + 1}] = 1;
        }
    }

    ll cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        if (mp1[{i, 1}] == 0) cnt1++;
        if (mp2[{1, i}] == 0) cnt2++;
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