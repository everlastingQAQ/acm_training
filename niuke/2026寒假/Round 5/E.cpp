#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, mod;
    cin >> n >> mod;
    vector <int> v(n + 1), pre(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pre[i] = (pre[i - 1] + v[i]) % mod;
        // cout << pre[i] << " \n"[i == n];
    }

    map <int, int> mp;
    set <int> st;
    int ans = 0, ansl = 1, ansr = 1;
    for (int i = 1; i <= n; i++) {
        auto it = st.upper_bound(pre[i]);
        if (it != st.end()) {
            int cur = (pre[i] - *it + mod) % mod;
            if (cur > ans) {
                ansl = mp[*it] + 1;
                ansr = i;
                ans = cur;
            }
        }
        st.insert(pre[i]);
        mp[pre[i]] = i;
        if (pre[i] > ans) {
            // cout << i << ' ' << i << '\n';
            ansl = 1;
            ansr = i;
            ans = pre[i];
        }
    }

    cout << ansl - 1 << ' ' << ansr - 1 << ' ' << ans << '\n';
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/