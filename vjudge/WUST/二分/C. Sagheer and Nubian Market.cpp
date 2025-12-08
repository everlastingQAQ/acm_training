#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, s, sum, ans1, ans2;
vector <ll> v;

bool cmp(ll a1, ll b1)
{
    return a1 < b1;
}

bool check (ll x)
{
    sum = 0;

    vector <ll> p(n);

    for (int i = 0; i < n; i++) {
        p[i] = v[i] + (i + 1) * x;
    }

    sort(p.begin(), p.end(), cmp);

    for (int i = 0; i < x; i++) {
        sum += p[i];
        if (sum > s) {
            return false;
        }
    }

    if (sum <= s) {
        return true;
    }else {
        return false;
    }
}

void solve ()
{
    v.clear();
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        v.push_back(t);
    }
    
    ll l = 0, r = n;

    while (l < r) {
        ll mid = l + (r - l + 1) / 2;
        if (check(mid)) {
            ans1 = mid;
            ans2 = sum;
            l = mid;
        }else {
            r = mid - 1;
        }
    }

    cout << ans1 << ' ' << ans2 << endl;
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