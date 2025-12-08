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
    set <ll> st;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        st.insert(v[i]);
        ans += v[i];
    }

    sort(v.begin(), v.end(), greater<ll> ());
    if (st.size() != n) {
        for (int i = n - 1; i >= 0; i--) {
            if (v[i] == v[i - 1]) {
                ans -= v[i];
                break;
            }
        }
        cout << n - 1 << ' ' << ans << '\n';
    }else {
        ans -= v[0];
        cout << n - 1 << ' ' << ans << '\n';
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