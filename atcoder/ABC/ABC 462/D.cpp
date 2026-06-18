#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, d;
    cin >> n >> d;
    using arr2 = array <int, 2>;
    vector <arr2> v(n + 1);
    int m = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
        m = max(m, v[i][1]);
    }
    sort(v.begin() + 1, v.end(), [] (auto a, auto b) {
        if (a[0] != b[0]) return a[0] < b[0];
        else return a[1] > b[1];
    });

    priority_queue <int, vector <int>, greater<int> > stk;
    int idx = 1;
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        while (idx <= n && v[idx][0] == i) {
            stk.push(v[idx][1]);
            idx++;
        }
        while (!stk.empty() && stk.top() < i + d) {
            stk.pop();
        }
        int cur = stk.size();
        if (cur >= 2) {
            int t = cur * (cur - 1) / 2;
            ans += t;
        } 
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