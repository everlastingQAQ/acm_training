#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n, k;
    cin >> n >> k;
    map <int, vector <int> > v;
    for (int i = 1; i <= k; i++) {
        int t;
        cin >> t;
        for (int j = 1; j <= t; j++) {
            int x;
            cin >> x;
            v[x].push_back(i);
        }
    }

    auto l = v.begin(), r = v.begin();
    unordered_map <int, int> mp;
    int cnt = 0;
    int ans = 1e11;

    while (r != v.end()) {
        int x = r->first;
        for (auto t : r->second) {
            if (mp[t] == 0) {
                cnt++;
            }
            mp[t]++;
        }
        if (cnt == k) {
            while (cnt == k && l != r) {
                ans = min(ans, r->first - l->first);
                for (auto t : l->second) {
                    if (--mp[t] == 0) {
                        cnt--;
                    }
                }
                l = next(l);
            }
        }
        r = next(r);
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