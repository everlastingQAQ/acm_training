#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n;
    cin >> n;
    set <int> st;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        st.insert(t);
    }
    int x; cin >> x;
    cout << (st.count(x) == 1 ? "Yes" : "No") << '\n';
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