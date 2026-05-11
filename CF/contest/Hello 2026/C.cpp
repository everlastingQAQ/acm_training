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
    ll n, m, k; cin >> n >> m >> k;
    if (k - 1 >= n - k) k = n + 1 - k;
    ll a = 0, b = 0;

    while (1) {
        if (a < k - 1 && (a + 1) + b + max(a + 1, b) - 1 <= m) a++;
        if (b < n - k && a + (b + 1) + max(a, b + 1) - 1 <= m) b++;
        else break;
    }

    cout << a + b + 1 << '\n';
}   

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}