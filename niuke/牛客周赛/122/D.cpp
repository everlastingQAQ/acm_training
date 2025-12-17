#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const ll MAXN = 1e7;
const ld eps = 1e-12;
const ll mod = 1e9 + 7;

ll n;

void solve ()
{
    cin >> n;
    vector <ll> v(n + 1);
    ll cnt_0 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] == 0) cnt_0++;
    }
    sort(v.begin() + 1, v.end());
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] > sum + 1) {
            cout << n - i + 1 + cnt_0 << '\n';
            return;
        }
        sum += v[i];    
    }
    cout << cnt_0 << '\n';
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