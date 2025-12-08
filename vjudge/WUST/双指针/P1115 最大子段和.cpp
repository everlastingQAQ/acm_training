#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve1 ()
{
    cin >> n;
    vector <ll> v(n + 1);
    vector <ll> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum[i] += v[i] + sum[i - 1];
        if (sum[i] < 0) {
            sum[i] = v[i];
        }
    }

    auto it = max_element(sum.begin() + 1, sum.end());

    cout << *it << '\n';
}

void solve2 ()
{
    cin >> n;
    ll a, b, ans = -1e5;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (i == 1) {
            b = a;
            continue;
        }
        b = max(a, a + b);
        ans = max(b, ans);
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
        solve1();
    }
    return 0;
}