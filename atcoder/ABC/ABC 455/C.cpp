#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    map <int, int> mp;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        mp[t]++;
        sum += t;
    }
    multiset <int> st;
    for (auto [x, y] : mp) {
        st.insert(x * y);
    }
    int cnt = 0;
    for (auto it = st.rbegin(); it != st.rend(); it++) {
        sum -= *it;
        if (++cnt == k) break;
    }
    cout << sum << '\n';
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