#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll q;

void solve ()
{
    set <ll> st;
    cin >> q;
    ll a;
    ll b;
    while (q--) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            st.insert(b);
        }else if (a == 2) {
            cin >> b;
            if (st.count(b)) {
                st.erase(b);
            }else {
                continue;
            }
            st.erase(b);
        }else if (a == 3) {
            cin >> b;
            if (st.count(b)) {
                cout << "Yes" << '\n';
            }else {
                cout << "No" << '\n';
            }
        }
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