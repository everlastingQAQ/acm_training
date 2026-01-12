#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<string, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll n; cin >> n;
    ll mx = 0;
    unordered_map <ll, ll> mp;
    set <ll> st;
    for (int i = 0; i < n; i++) {
        ll t; cin >> t;
        st.insert(t);
        mp[t]++;
        mx = max(mx, t);
    }

    vector <ll> v;
    v.emplace_back(0);
    for (int i = 1; i <= mx; i++) {
        v.emplace_back(i * mp[i]);
    }

    vector <ll> dp(mx + 1);
    dp[0] = 0;
    dp[1] = v[1];
    for (int i = 2; i <= mx; i++) {
        dp[i] = max(dp[i - 2] + v[i], dp[i - 1]);
    }   
    cout << dp[mx];
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