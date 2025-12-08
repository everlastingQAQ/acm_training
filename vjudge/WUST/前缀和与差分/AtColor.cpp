#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1000000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;
    
    vector <ll> d(MAXN + 2, 0);
    vector <ll> ans(MAXN + 2, 0);

    ll a, b;
    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        mx = max(mx, b);
        d[a]++;
        d[b + 1]--;
    }

    ans[0] = d[0];
    for (int i = 1; i <= mx + 1; i++) {
        ans[i] = ans[i - 1] + d[i];
    }

    auto it = max_element(ans.begin(), ans.begin() + mx + 2);

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