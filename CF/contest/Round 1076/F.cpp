#include <bits/stdc++.h>
using namespace std;
#define int long long

struct point {
    int x, y;
    bool operator < (const point &a) const {
        if (x != a.x) return x < a.x;
        else return y < a.y;
    }
};

void solve ()
{
    int n; cin >> n;
    point s, e; cin >> s.x >> s.y >> e.x >> e.y;
    vector <point> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].x;
    for (int i = 0; i < n; i++) cin >> v[i].y;

    sort(v.begin(), v.end());

    vector <vector<array<int, 2> > > a; 

    int idx = 0, cnt = 0;
    while (idx < n) {
        int t = v[idx].x;
        a.push_back({});
        while (idx < n && v[idx].x == t) {
            a[cnt].push_back({idx, t});
            idx++;
        }
        cnt++;
    }

    vector <array<int, 3> > b(cnt);
    for (int i = 0; i < cnt; i++) {
        b[i][0] = v[a[i].back()[0]].y;
        b[i][1] = v[a[i].front()[0]].y;
        b[i][2] = a[i].front()[1];
    }

    vector <array<int, 2> > dp(cnt);
    dp[0][0] = b[0][2] - s.x + min(abs(b[0][1] - s.y) + b[0][0] - b[0][1], abs(s.y - b[0][0]) + 2 * (b[0][0] - b[0][1]));
    dp[0][1] = b[0][2] - s.x + min(abs(s.y - b[0][0]) + b[0][0] - b[0][1], abs(s.y - b[0][1]) + 2 * (b[0][0] - b[0][1]));

    for (int i = 1; i < cnt; i++) {
        int t1 = dp[i - 1][0] + b[i][2] - b[i - 1][2];
        int tt1 = min(abs(b[i - 1][0] - b[i][1]) + (b[i][0] - b[i][1]), abs(b[i - 1][0] - b[i][0]) + 2 * (b[i][0] - b[i][1]));
        int t2 = dp[i - 1][1] + b[i][2] - b[i - 1][2];
        int tt2 = min(abs(b[i - 1][1] - b[i][1]) + (b[i][0] - b[i][1]), abs(b[i - 1][1] - b[i][0]) + 2 * (b[i][0] - b[i][1]));
        dp[i][0] = min(t1 + tt1, t2 + tt2);

        int x1 = dp[i - 1][0] + b[i][2] - b[i - 1][2];
        int xx1 = min(abs(b[i - 1][0] - b[i][0]) + (b[i][0] - b[i][1]), abs(b[i - 1][0] - b[i][1]) + 2 * (b[i][0] - b[i][1]));
        int x2 = dp[i - 1][1] + b[i][2] - b[i - 1][2];
        int xx2 = min(abs(b[i - 1][1] - b[i][0]) + (b[i][0] - b[i][1]), abs(b[i - 1][1] - b[i][1]) + 2 * (b[i][0] - b[i][1]));
        dp[i][1] = min(x1 + xx1, x2 + xx2);
    }

    int ans = min(
        dp[cnt - 1][0] + e.x - b[cnt - 1][2] + abs(e.y - b[cnt - 1][0]), 
        dp[cnt - 1][1] + e.x - b[cnt - 1][2] + abs(b[cnt - 1][1] - e.y)
    );

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