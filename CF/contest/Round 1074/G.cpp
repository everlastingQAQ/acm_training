#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    vector <vector <int> > v(n + 1);
    vector <array<int, 2> > mex(n + 1, {0, 0});
    int total = 0;
    unordered_map <int, int> mp;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        v[i].resize(t + 1);
        total += t;
        for (int j = 1; j <= t; j++) {
            cin >> v[i][j];
            mp[v[i][j]]++;
        }

        ranges::sort(v[i] | views::drop(1));
        int idx = t;
        for (int j = 1; j <= t; j++) {
            if (v[i][j] == mex[i][0]) mex[i][0]++;
            else if (v[i][j] > mex[i][0]) {
                idx = j; 
                break;
            }
        }
        mex[i][1] = mex[i][0] + 1;
        for (int j = idx; j <= t; j++) {
            if (v[i][j] == mex[i][1]) mex[i][1]++;
            else if (v[i][j] > mex[i][1]) break;
        }   
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = v[i].size() - 1;
        ans += mex[i][0] * (total - cnt) * (n - 2); 
        for (int j = 1; j <= cnt; j++) {
            if (j + 1 <= cnt && v[i][j] == v[i][j + 1]) {
                ans += mex[i][0] * (n - 1);
            }else if (j >= 2 && v[i][j] == v[i][j - 1]) {
                ans += mex[i][0] * (n - 1);
            }else if (v[i][j] > mex[i][0]) {
                ans += mex[i][0] * (n - 1);
            }else {
                ans += v[i][j] * (n - 1);
            }
        }
        ans += mp[mex[i][0]] * mex[i][1] + (total - mp[mex[i][0]] - cnt) * mex[i][0];
    }

    cout << ans << '\n';
}   
    
signed main ()
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