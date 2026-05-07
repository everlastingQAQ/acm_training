#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll n; cin >> n;
    vector <array<ll, 2> > v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
        sum += v[i][1];
    } 

    sort(v.begin(), v.end(), [] (auto a1, auto b1) {
        return a1[0] + a1[1] < b1[0] + b1[1];
    });

    ll ans = 0;
    ll t = 0;
    for (int i = 0; i < n; i++) {
        if (t + v[i][0] + v[i][1] <= sum) {
            ans++;
            t += v[i][0] + v[i][1];
        }else break;
    }

    cout << ans << '\n';
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