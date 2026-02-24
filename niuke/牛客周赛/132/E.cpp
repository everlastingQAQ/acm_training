#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int vis[1000000 + 1];

void solve ()
{
    i64 a, b, k;
    cin >> a >> b >> k;
    memset(vis, 0, sizeof vis);

    i64 ans = 0;
    queue <array <i64, 2> > q;
    q.push({a, 0LL});
    vis[a] = true;
    
    while (q.size()) {
        auto [t, cnt] = q.front();
        q.pop();
        if (t == b) {
            cout << cnt << '\n';
            return;
        }
        
        if (t + k <= 1e6 && !vis[t + k]) {
            q.push({t + k, cnt + 1});
            vis[t + k] = true;
        }

        if (t % 10 != 0) {
            i64 cur = 0;
            while (t != 0) {
                cur = cur * 10 + t % 10;
                t /= 10;
            }

            if (cur <= 1e6 && !vis[cur]) {
                q.push({cur, cnt + 1});
                vis[cur] = true;
            }
        }
    }

    cout << -1 << '\n';
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/