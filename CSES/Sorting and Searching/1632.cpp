#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    multiset <int> st;
    for (int i = 0; i < k; i++) {
        st.insert(0);
    }
    vector <array<int, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    sort(v.begin() + 1, v.end(), [] (auto a, auto b) {
        if (a[1] != b[1]) return a[1] < b[1];
        else return a[0] < b[0];
    });

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        auto it = st.upper_bound(v[i][0]);
        if (it == st.begin()) continue;
        it--;
        st.erase(it);
        st.insert(v[i][1]);
        ans++;
    }

    cout << ans << '\n';
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