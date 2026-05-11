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
    vector <ll> v(n);

    for (ll &i : v) {
        cin >> i;
    }

    ll cnt = 1;
    for (int i = 1; i < n - 1; i++) {
        if (v[i - 1] + 1 <= v[i] && v[i] + 1 <= v[i + 1]) {
            cnt++;
            i++;
        }else {
            cnt++;
        }
    }

    cout << 
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