#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
 
ll n, m;

void solve ()
{
    cin >> n >> m;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    vector <ll> a(n + 1, 0);
    for (int j = 1; j <= m; j++) {
        ll cnt_0 = 0;
        ll cnt_1 = 0;
        for (int i = 1; i <= n; i++) {
            if (v[i][j] == '1') {
                cnt_1++;
            }else {
                cnt_0++;
            }
        }
        if (cnt_1 > cnt_0) {
            for (int i = 1; i <= n; i++) {
                if (v[i][j] == '0') {
                    a[i]++;
                }
            }
        }else if (cnt_1 < cnt_0) {
            for (int i = 1; i <= n; i++) {
                if (v[i][j] == '1') {
                    a[i]++;
                }
            }
        }
    }

    vector <ll> ans;
    ll mx = *max_element(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) {
        if (a[i] == mx) {
            ans.emplace_back(i);
        }
    }

    sort(ans.begin(), ans.end());

    for (auto x : ans) {
        cout << x << ' ';
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