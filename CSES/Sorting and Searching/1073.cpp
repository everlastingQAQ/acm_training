#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    multiset <int> st;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        auto it = st.upper_bound(x);
        if (it == st.end()) {
            st.insert(x);
        }else {
            st.erase(it);
            st.insert(x);
        }
    }
    cout << st.size() << '\n';
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