#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using arr2 = array <int, 2>;

void solve ()
{
    int n;
    cin >> n;
    vector <int> a(n + 1), ind(n + 1);
    vector <vector <int> > rev(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ind[a[i]]++;
        rev[a[i]].push_back(i);
    }

    // 一.建基环树
    // 1.topo判环
    vector <int> removed(n + 1);
    queue <int> q;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        removed[u] = true;
        int v = a[u];
        if (--ind[v] == 0) q.push(v);
    }

    // 2.建环
    vector <vector <int> > cycle;
    vector <int> vis(n + 1, 0);
    int id = 0;
    for (int i = 1; i <= n; i++) {
        if (removed[i] || vis[i]) continue;
        vector <int> cyc;
        int u = i;
        while (!vis[u]) {
            vis[u] = 1;
            cyc.push_back(u);
            u = a[u];
        }
        cycle.push_back(cyc);
    }

    // 3.初始化树的信息
    vector <int> comp(n + 1), pos(n + 1), dep(n + 1), root(n + 1);
    int sum_cyc = cycle.size();

    for (int id = 0; id < sum_cyc; id++) {
        for (int i = 0; i < cycle[id].size(); i++) {
            int u = cycle[id][i];
            comp[u] = id;
            pos[u] = i;
            dep[u] = 0;
            root[u] = u;
        }
    }

    // 4.建反树
    vector <vector <int> > e(n + 1);
    for (int u = 1; u <= n; u++) {
        for (auto v : rev[u]) {
            if (removed[v]) {
                e[u].push_back(v);
            }
        }
    }

    // 5.求dfs序
    vector <int> tin(n + 1), tout(n + 1);
    int time = 0;

    auto dfs = [&] (auto self, int u) -> void {
        tin[u] = ++time;
        for (auto v : e[u]) {
            comp[v] = comp[u];
            root[v] = root[u];
            dep[v] = dep[u] + 1;
            self(self, v);
        }
        tout[u] = time;
    };

    for (auto &cyc : cycle) {
        for (auto r : cyc) {
            dfs(dfs, r);
        }
    }

    // 二.计算答案

    // 1.初始化
    int m;
    cin >> m;
    vector <int> len(sum_cyc);
    vector <vector <int> > cyc_info(sum_cyc);
    for (int id = 0; id < sum_cyc; id++) {
        len[id] = cycle[id].size();
        cyc_info[id].assign(len[id], 0);
    }

    vector <vector <arr2> > update(m + 1);
    unordered_map <int, ordered_set<arr2> > mp;
    mp.reserve(m * 2 + 10);

    int pre = 0;

    for (int i = 1; i <= m; i++) {
        for (auto [id, c_id] : update[i]) {
            cyc_info[id][c_id]++;
        }
        int x;
        cin >> x;
        x = (x ^ pre);

        // 2.插入
        if (!removed[x]) {
            int id = comp[x];
            int c_id = ((pos[x] - i) % len[id] + len[id]) % len[id];
            cyc_info[id][c_id]++;
        }else {
            int key = i + dep[x];
            mp[key].insert({tin[x], i});
            int T = i + dep[x];
            if (T <= m) {
                int id = comp[x];
                int c_id = ((pos[root[x]] - T) % len[id] + len[id]) % len[id];
                update[T].push_back({id, c_id});
            }
        }

        // 3.查询
        int res = 0;
        if (!removed[x]) {
            int id = comp[x];
            int c_id = ((pos[x] - i) % len[id] + len[id]) % len[id];
            res = cyc_info[id][c_id];
        }else {
            int key = i + dep[x];
            auto it = mp.find(key);
            if (it != mp.end()) {
                auto &st = it->second;
                res = st.order_of_key({tout[x] + 1, -1}) - st.order_of_key({tin[x], -1});
            }
        }

        cout << res << '\n';
        pre = res;
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