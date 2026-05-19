#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> b(m + 1);
    multiset <int> st;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }
    for (int i = 1; i <= m; i++) {
        int t;
        cin >> t;
        auto it = st.upper_bound(t);
        if (it == st.begin()) {
            cout << -1 << '\n';
        }else {
            it--;
            cout << *it << '\n';
            st.erase(it);
        }
    }

}   
    
int32_t main ()
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