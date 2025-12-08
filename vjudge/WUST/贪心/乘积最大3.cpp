#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, m;

void solve ()
{
    cin >> n >> m;

    ll a = n / m;
    ll b = n % m;

    vector <ll> v;
    for (int i = 0; i < m; i++) {
        if (i < b) {
            v.push_back(a + 1);
        }else {
            v.push_back(a);
        }
    }
    sort(v.begin(), v.end());

    for (auto x : v) {
        cout << x << ' ';
    }
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