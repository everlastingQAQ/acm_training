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
 
ll n, q;

void solve ()
{   
    cin >> n >> q;
    vector <ll> v(n);
    set <ll> st;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        st.insert(v[i]);
    }
    
    vector <ll> a;
    for (int i = 0; i < n; i++) {
        if (v[i] != 1) {
            a.push_back(v[i]);
        }
    }

    ll m = a.size();

    for (int i = 0; i < m; i++) {
        ll t = a[i];
        for (int j = i + 1; j < m; j++) {
            t *= a[j];
            if (t > 1e9 + 5) {
                break;
            }
            st.insert(t);
        }
    }

    while (q--) {
        ll x;
        cin >> x;
        if (st.count(x)) {
            cout << "Yes" << '\n';
        }else {
            cout << "No" << '\n';
        }
    }

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