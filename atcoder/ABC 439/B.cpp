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

void solve ()
{
    ll n; cin >> n;
    set <ll> st;
    ll t = n;

    while (1) {
        ll temp = 0;
        while (t > 0) {
            temp += (t % 10) * (t % 10);
            t /= 10;
        }
        t = temp;
        if (t == 1) {
            cout << "Yes";
            return;
        }
        if (st.count(t)) {
            cout << "No";
            return;
        }else {
            st.insert(t);
        }
    }
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}   