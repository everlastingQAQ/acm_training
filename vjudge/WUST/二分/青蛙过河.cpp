#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, x;
vector <ll> v;
vector <ll> sum;

bool check (ll p)
{
    for (int i = p; i < n; i++) {
        if (sum[i] - sum[i - p] < 2 * x) {
            return false;
        }
    }
    return true;
}

void solve ()
{
    cin >> n >> x;

    v.resize(n + 1);
    sum.resize(n + 1);
    sum[0] = 0;
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        sum[i] = sum[i - 1] + v[i];
    }

    ll l = 1, r = n;
    ll ans = 0;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
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