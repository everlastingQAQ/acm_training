#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;

void solve ()
{
    cin >> n;
    vector <ll> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    ll l, r;
    cin >> l >> r;
    if (r * n < sum || l * n > sum) {
        cout << -1 << '\n';
        return;
    }

    ll cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] < l) {
            cnt1 += l - v[i];
        }else if (v[i] > r) {
            cnt2 += v[i] - r;
        }
    }

    cout << max(cnt1, cnt2) << '\n';
    
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