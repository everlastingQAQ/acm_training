#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    vector <vector <int> > e(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        e[v[i]].push_back(i);
    }
    vector <int> vis(n + 1, 0);//to
    vector <int> ans(n + 1);//head
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!e[i].empty()) {
            int x = e[i].front();
            vis[i] = true;
            ans[x] = i;
            cnt++;
        }
    }
    vector <int> head, to;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            to.push_back(i);
        }
        if (ans[i] == 0) {
            head.push_back(i);
        }
    }

    vector <int> a;
    for (int i = 0; i < to.size(); i++) {
        if (head[i] == to[i]) {
            a.push_back(i);
        }else {
            ans[head[i]] = to[i];
        }
    }

    if (a.size() > 1) {
        int x = a.size();
        for (int i = 0; i < x; i++) {
            ans[head[a[i]]] = to[a[(i + 1) % x]];
        }
    }else if (a.size() == 1) {
        int x = head[a.front()];
        int y = v[x];
        int t;
        for (int i = 1; i <= n; i++) {
            if (ans[i] == y) {
                t = i;
                break;
            }
        }
        ans[x] = y;
        ans[t] = x;
    }

    cout << cnt << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }

}   
    
int32_t main ()
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