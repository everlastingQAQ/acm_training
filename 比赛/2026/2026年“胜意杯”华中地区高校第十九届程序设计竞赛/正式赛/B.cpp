#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector <vector <int> > e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector <int> c(n + 1, -1);
    vector <int> comp(n + 1, -1);
    vector <int> bip;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (comp[i] != -1) continue;
        queue <int> q;
        q.push(i);
        comp[i] = cnt;
        c[i] = 0;
        bip.push_back(1);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : e[u]) {
                if (comp[v] != -1) {
                    if (c[v] == c[u]) {
                        bip[cnt] = 0;
                    }
                }else {
                    comp[v] = cnt;
                    c[v] = c[u] ^ 1;
                    q.push(v);
                }
            }
        }

        cnt++;
    }

    vector <int> a(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }

    vector <int> b(k + 1);
    for (int i = 1; i <= k; i++) {
        if (!bip[comp[a[i]]]) {
            b[i] = 2 * comp[a[i]];
        }else {
            b[i] = 2 * comp[a[i]] + (c[a[i]] ^ (i & 1));
        }
    }

    vector <i64> nxt(k + 1, 1e18);
    vector <i64> last(2 * cnt + 10, 1e18);

    for (int i = k; i >= 1; i--) {
        nxt[i] = last[b[i]];
        last[b[i]] = i;
    }

    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        if (nxt[l] <= r) {
            cout << "Fern\n";
        }else {
            cout << "Stark\n";
        }
    }
}   

int main ()
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