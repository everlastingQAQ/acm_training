#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, m;

void solve ()
{
    cin >> n >> m;
    vector <ll> v(n + 5);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector <ll> stk(1, 0);
    vector <pair<ll, ll> > a;
    vector <ll> b;

    for (int i = 1; i <= n + 1; i++) {
        while (v[stk.back()] > v[i]) {
            ll bk1 = stk.back();
            stk.pop_back();
            ll bk2 = stk.back();
            ll mx = max(v[i], v[bk2]);
            ll cnt = v[bk1] - mx;
            b.emplace_back(cnt);
            a.emplace_back(bk1, i - 1);
            if (v[i] > v[bk2]) {
                stk.emplace_back(bk1);
            }
            v[bk1] = mx;
        }
        if (v[stk.back()] < v[i]) {
            stk.emplace_back(i);
        }
    }

    for (ll &i : b) {
        m -= i;
    }

    if (m < 0) {
        cout << -1 << '\n';
        return;
    }

    vector <pair<ll, ll> > ans;
    for (int i = 0; i < b.size(); i++) {
        ll cnt = b[i];
        auto [L, R] = a[i];
        for (int j = 0; j < cnt; j++) {
            ll l = L, r = R;
            while (m > 0 && l < r) {
                ans.emplace_back(l, l);
                l++;
                m--;
            }
            ans.emplace_back(l, r);
        }
    }

    if (m > 0) {
        cout << -1 << '\n';
        return;
    }

    for (auto &[L, R] : ans) {
        cout << L << ' ' << R << '\n';
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