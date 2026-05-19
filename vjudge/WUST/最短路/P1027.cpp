#include <bits/stdc++.h>
using namespace std;
#define int long long
using ld = long double;

struct point {
    int x, y;
    point operator + (const point &other) const {
        return point(x + other.x, y + other.y);
    }
    point operator - (const point &other) const {
        return point(x - other.x, y - other.y);
    }
    bool operator < (const point &other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

struct edge {
    int v;
    ld w;
};

void solve ()
{
    int n, t, a, b;
    cin >> n >> t >> a >> b;
    vector <vector <edge> > e(4 * n + 10);
    vector <point> v(4 * n + 100);
    int cnt = 1;

    auto dis = [&] (point a, point b) -> ld {
        int x = (a.x - b.x) * (a.x - b.x);
        int y = (a.y - b.y) * (a.y - b.y);
        return sqrtl(x + y);
    };

    map <point, int> mp;

    for (int i = 1; i <= n; i++) {
        vector <point> p(4);
        ld T;
        cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y >> T;
        ld dis1 = dis(p[0], p[1]);
        ld dis2 = dis(p[0], p[2]);
        ld dis3 = dis(p[1], p[2]);
        if (dis1 >= dis2 && dis1 >= dis3) {
            p[3] = p[0] + p[1] - p[2];
        }else if (dis2 >= dis1 && dis2 >= dis3) {
            p[3] = p[0] + p[2] - p[1];
        }else {
            p[3] = p[1] + p[2] - p[0];
        }

        for (int j = 0; j < 4; j++) {
            v[cnt] = p[j];
            mp[p[j]] = cnt++;
        }

        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                int p1 = mp[p[i]], p2 = mp[p[j]];
                ld w = dis(p[i], p[j]);
                e[p1].push_back({p2, T * w});
                e[p2].push_back({p1, T * w});
            }
        } 
    }

    for (int i = 1; i < cnt; i++) {
        for (int j = i + 1; j < cnt; j++) {
            int ci = (i - 1) / 4 + 1;
            int cj = (j - 1) / 4 + 1;
            if (ci == cj) continue;
            ld w = dis(v[i], v[j]) * t;
            e[i].push_back({j, w});
            e[j].push_back({i, w});
        }
    }

    auto dij = [&] (int st, int en) -> ld {
        vector <ld> dis(4 * n + 1, 1e18);
        priority_queue <pair <ld, int> , vector <pair <ld, int> >, greater <pair <ld, int> > > pq;
        dis[st] = 0;
        pq.push({0, st});
        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();
            if (dist > dis[u]) continue;
            for (auto [v, w] : e[u]) {
                if (dis[v] > dist + w) {
                    dis[v] = dist + w;
                    pq.push({dis[v], v});
                }
            } 
        }
        return dis[en];
    };

    ld ans = 1e18;
    for (int i = 4 * (a - 1) + 1; i <= 4 * a; i++) {
        for (int j = 4 * (b - 1) + 1; j <= 4 * b; j++) {
            ans = min(ans, dij(i, j));
        }
    }

    cout << fixed << setprecision(1);
    cout << ans << '\n';
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