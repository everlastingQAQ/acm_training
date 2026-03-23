#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector <i64> dp(n + 1);
    set <i64> st;
    unordered_map <i64, int> mp;
    dp[1] = v[1];
    st.insert(dp[1]);
    mp[dp[1]] = 1;
    i64 mx = dp[1];

    for (int i = 2; i <= k; i++) {
        mx = *st.rbegin();
        dp[i] = mx + v[i];
        mp[dp[i]]++;
        st.insert(dp[i]);
    }

    for (int i = k + 1; i <= n; i++) {
        
        mx = *st.rbegin();
        dp[i] = mx + v[i];

        st.insert(dp[i]);
        mp[dp[i]]++;
        
        if (--mp[dp[i - k]] == 0) {
            st.erase(dp[i - k]);
        }
        
    }

    cout << dp[n] << '\n';
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