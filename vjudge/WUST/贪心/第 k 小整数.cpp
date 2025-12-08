#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, k;

void solve ()
{
    cin >> n >> k;
    set <ll> st;

    for (int i = 1; i <= n; i++) {
        ll t;
        cin >> t;
        st.insert(t);
    }

    if (k > st.size()) {
        cout << "NO RESULT\n";
        return;
    }
    auto it = st.begin();
    advance(it, k - 1);
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