#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> ans(n + 1);
    vector <vector <int> > e(n + 1);
    vector <int> vis_head(n + 1, 0);
    vector <int> vis_to(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> ans[i];
        if (ans[i] != 0) {
            vis_head[i] = true;
            vis_to[ans[i]] = true;
            e[ans[i]].push_back(i);
        }
    }

    vector <int> head, to;
    for (int i = 1; i <= n; i++) {
        if (!vis_head[i]) {
            head.push_back(i);
        }
        if (!vis_to[i]) {
            to.push_back(i);
        }
    }

    int xx;
    vector <int> v;
    for (int i = 0; i < head.size(); i++) {
        if (head[i] == to[i]) {
            v.push_back(i);
        }else {
            ans[head[i]] = to[i];
            xx = to[i];
        }
    }

    int m = v.size();
    if (m == 1) {
        int x = head[v.front()];
        int y;
        for (int i = 1; i <= n; i++) {
            if (ans[i] == xx) {
                y = i;
                break;
            }
        }
        ans[y] = x;
        ans[x] = xx;
    }else { 
        for (int i = 0; i < m; i++) {
            ans[head[v[i]]] = to[v[(i + 1) % m]];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}
