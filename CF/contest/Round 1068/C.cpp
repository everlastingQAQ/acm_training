#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
    
ll n, k;

void solve ()
{
    cin >> n >> k;
    vector <ll> v(n);
    map <ll, bool> mpp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mpp[v[i]] = true;
    }
    sort(v.begin(), v.end());

    map <ll, bool> mp;
    vector <ll> ans;

    for (int i = 0; i < n; i++) {
        if (!mp[v[i]]) {
            ans.push_back(v[i]);
            ll t = v[i];
            while (t <= k) {
                // cout << t << '\n';
                if (!mpp[t]) {
                    cout << -1 << '\n';
                    return;
                }
                mp[t] = true;
                t += v[i];
            }
        }else {
            continue;
        }
    }
    
    if (ans.size() == 0) {
        cout << -1 << '\n';
    }else {
        cout << ans.size() << '\n';
        for (auto x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    
}
 
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}