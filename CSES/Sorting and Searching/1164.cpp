#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    using arr2 = array <int, 2>;
    using arr3 = array <int, 3>;
    vector <arr3> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    sort(v.begin() + 1, v.end());
    priority_queue <arr2, vector <arr2>, greater<arr2> > pq;
    vector <int> ans(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!pq.empty() && pq.top()[0] < v[i][0]) {
            auto [x, y] = pq.top();
            pq.pop();
            ans[v[i][2]] = y;
            pq.push({v[i][1], y});
        }else {
            cnt++;
            pq.push({v[i][1], cnt});
            ans[v[i][2]] = cnt;
        }
    }
    cout << cnt << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
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