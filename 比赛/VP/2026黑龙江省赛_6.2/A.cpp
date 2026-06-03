#include <bits/stdc++.h>
using namespace std;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > e(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector <vector <int> > path(m + 1);
    vector <int> kaka, ee, yaya, zhongli;
    vector <vector <int> > kakapath, eepath, yayapath, zhonglipath;
    vector <int> iswho(m + 1);
    vector <int> tm(m + 1);

    auto cal = [&] (int st, int en) -> vector <int> {
        vector <int> x;
        queue <int> q;
        q.push(st);
        vector <int> vis(n + 1);
        vis[st] = true;
        vector <int> pre(n + 1);
        
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            if (u == en) {
                int cur = u;
                while (cur != st) {
                    x.push_back(cur);
                    cur = pre[cur];
                }
                x.push_back(cur);
                reverse(x.begin(), x.end());
                break;
            }
            for (auto v : e[u]) {
                if (vis[v]) continue;
                pre[v] = u;
                vis[v] = true;
                q.push(v);
            }
        }

        return x;
    };

    int id = 1;
    for (int i = 1; i <= m; i++) {
        int op, t, st, en;
        cin >> op >> t >> st >> en;
        if (op == 1) {
            kaka.push_back(id);
            kakapath.push_back(cal(st, en));
            iswho[id] = op;
            tm[id] = t;
            id++;
        }else if (op == 2) {
            ee.push_back(id);
            eepath.push_back(cal(st, en));
            iswho[id] = op;
            tm[id] = t;
            id++;
        }else if (op == 3) {
            yaya.push_back(id);
            yayapath.push_back(cal(st, en));
            iswho[id] = op;
            tm[id] = t;
            id++;
        }else if (op == 4) {
            zhongli.push_back(id);
            zhonglipath.push_back(cal(st, en));
            iswho[id] = op;
            tm[id] = t;
            id++;
        }
    }

    vector <int> over(m + 1);
    int cnt = 0;
    int ans = 0;
    int time = 1;
    vector <int> res;

    while (cnt < m) {
        vector <vector <array <int, 2> > > cur(n + 1);
        for (int i = 0; i < kaka.size(); i++) {
            if (over[kaka[i]]) continue;
            if (time >= kakapath[i].size() - 1) {
                over[kaka[i]] = true;
                cnt++;
                ans++;
                res.push_back(kaka[i]);
            }else {
                cur[kakapath[i][time]].push_back({kaka[i], 1});
            }
        }
        for (int i = 0; i < yaya.size(); i++) {
            if (over[yaya[i]]) continue;
            if (time >= yayapath[i].size() - 1) {
                over[yaya[i]] = true;
                cnt++;
                ans++;
                res.push_back(yaya[i]);
            }else {
                cur[yayapath[i][time]].push_back({yaya[i], 3});
            }
        }
        for (int i = 0; i < ee.size(); i++) {
            if (over[ee[i]]) continue;
            if (time >= eepath[i].size() - 1) {
                over[ee[i]] = true;
                cnt++;
                ans++;
                res.push_back(ee[i]);
            }else {
                cur[eepath[i][time]].push_back({ee[i], 2});
            }
        }
        for (int i = 0; i < zhongli.size(); i++) {
            if (over[zhongli[i]]) continue;
            if (time >= zhonglipath[i].size() - 1) {
                over[zhongli[i]] = true;
                cnt++;
                ans++;
                res.push_back(zhongli[i]);
            }else {
                cur[zhonglipath[i][time]].push_back({zhongli[i], 4});
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (!cur[i].empty()) {
                int ok[5] = {};
                vector <int> id4, id1;
                for (auto [id, op] : cur[i]) {
                    if (time >= tm[id] && time % tm[id] == 0 && !over[id]) {
                        ok[op]++;
                        if (op == 4) {
                            id4.push_back(id);
                        }
                        if (op == 1) {
                            id1.push_back(id);
                        }
                    }
                }
                
                if (ok[2]) {
                    for (auto [id, op] : cur[i]) {
                        if (op == 1 && !over[id]) {
                            over[id] = true;
                            cnt++;
                            break;
                        }
                    }
                }

                if (ok[3]) {
                    for (auto [id, op] : cur[i]) {
                        if (op == 2 && !over[id]) {
                            over[id] = true;
                            cnt++;
                        }
                    }
                }

                if (ok[4] == 1) {
                    for (auto [id, op] : cur[i]) {
                        if (id4.back() != id && op != 1 && !over[id]) {
                            if (!over[id]) {
                                over[id] = true;
                                cnt++;
                            }
                        }
                    }
                }else if (ok[4] > 1) {
                    for (auto [id, op] : cur[i]) {
                        if (!over[id] && op != 1) {
                            over[id] = true;
                            cnt++;
                        }
                    }
                }

                if (ok[1] && !over[id1.back()]) {
                    for (auto [id, op] : cur[i]) {
                        if (!over[id] && op != 1) {
                            over[id] = true;
                            cnt++;
                        }
                    }
                }
            }
        }
        time++;
    }

    cout << ans << '\n';
    sort(res.begin(), res.end());
    for (auto x : res) {
        cout << x << '\n';
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