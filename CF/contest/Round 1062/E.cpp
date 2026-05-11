#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, k, x;

bool cmp (ll a1, ll b1)
{
    return a1 < b1;
}

bool check (ll m, vector <ll> &v)
{
    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += max(1LL * 0, v[i + 1] - v[i] - 2 * m + 1);
    }
    sum += max(1LL * 0, v[0] - m + 1);
    sum += max(1LL * 0, x - v.back() - m + 1);

    if (sum >= k) {
        return true;
    }else {
        return false;
    }
}

void solve ()
{
    cin >> n >> k >> x;

    vector <ll> v(n);

    for (ll &i : v) {
        cin >> i;
    }

    sort(v.begin(), v.end(), cmp);

    ll l = 0, r = x + 1;

    ll ans = 0;
    while (l < r) {
        ll mid = l + (r - l + 1) / 2;
        if (check(mid, v)) {
            ans = mid;
            l = mid;
        }else {
            r = mid - 1;
        }
    }

    vector <ll> p;
    ll pos = 0;
    for (int i = 0; i < n; i++) {
        while (p.size() < k && pos + ans <= v[i]) {
            p.emplace_back(pos++);
        }
        pos = max(pos, v[i] + ans);
    }

    while (p.size() < k && pos <= x) {
        p.emplace_back(pos++);
    }

    for (ll o : p) {
        cout << o << ' ';
    }

    cout << '\n';

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