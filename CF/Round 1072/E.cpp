#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1), d(n + 3);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        d[i] = abs(v[i] - v[i - 1]);
    }

    vector <int> al(n + 3, 1), br(n + 3, n + 1);
    vector <int> stk;

    for (int i = 2; i <= n; i++) {
        while (stk.size() && d[stk.back()] > d[i]) {
            stk.pop_back();
        }
        if (stk.size()) al[i] = stk.back();
        stk.push_back(i);
    }

    stk.clear();
    for (int i = n; i >= 2; i--) {
        while (stk.size() && d[stk.back()] >= d[i]) {
            stk.pop_back();
        }
        if (stk.size()) br[i] = stk.back();
        stk.push_back(i);
    }

    vector <int> ans(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        ans[d[i]] += (br[i] - i) * (i - al[i]);
    }

    for (int i = n - 2; i >= 1; i--) {
        ans[i] += ans[i + 1];
    }

    for (int i = 1; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
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