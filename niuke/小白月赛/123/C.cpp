#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
    
ll n, m;

bool check(ll x, const vector <ll> &cnt) 
{
    ll q = 0;
    for (auto p : cnt) {
        if (p % x == 0) {
            q += p / x;
        }else {
            q += p / x + 1;
        }
        if (q > m) {
            return false;
        }
    }
    return q <= m;
}

void solve ()
{
    cin >> n >> m;
    vector <ll> v(n + 5, 0);
    vector <ll> d(n + 5, 0);
    vector <ll> cnt;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (i == 1) {
            continue;
        }
        d[i] = v[i] - v[i - 1];
        if (d[i] <= 0) {
            cnt.push_back(-d[i] + 1);
        }
    }

    if (cnt.size() > m) {
        cout << -1 << '\n';
        return;
    }
    
    if (cnt.empty()) {
        cout << 0 << '\n';
        return;
    }

    ll r = *max_element(cnt.begin(), cnt.end());
    ll l = 1;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid, cnt)) {
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
    cin >> _; 
    while (_--) {
        solve();
    }
    return 0;
}