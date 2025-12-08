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
    v[0] = 1;

    vector <ll> a(n + 1);
    vector <ll> b(n + 2);
    a[1] = v[1];
    b[n] = v[n];
    for (int i = 2; i <= n; i++) {
        a[i] = gcd(v[i], a[i - 1]);
    }

    for (int i = n - 1; i > 0; i--) {
        b[i] = gcd(v[i], b[i + 1]);
    }

    vector <ll> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            ans[i] = b[2];
            continue;
        }else if (i == n) {
            ans[i] = a[n - 1];
            continue;
        }
        ans[i] = gcd(a[i - 1], b[i + 1]);
    }

    auto it = max_element(ans.begin() + 1, ans.end());

    cout << *it << '\n';
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