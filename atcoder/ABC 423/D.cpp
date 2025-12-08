#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ll n, k;

void solve ()
{
    cin >> n >> k;
    vector <ll> a(n);
    vector <ll> b(n);
    vector <ll> c(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector <ll> ans(n, -1);
    ll sum = 0;
    ll t = 0;

    priority_queue <pi, vector<pi>, greater<pi> > q;

    for (ll i = 0; i < n; i++) {
        t = max(t, a[i]);
        while (sum + c[i] > k) {
            auto [j, l] = q.top();
            q.pop();
            t = max(t, j);
            sum -= l;
        }
        ans[i] = t;
        q.push({t + b[i], c[i]});
        sum += c[i];
    }
    
    for (ll i = 0; i < n; i++) {
        cout << ans[i] << '\n';
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