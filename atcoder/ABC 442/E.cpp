#include <bits/stdc++.h>
using namespace std;
#define int long long

struct point 
{
    int x, y;
    int id;
};

inline bool cmp (const point &A, const point &B) //顺时针极角排序
{
    int ax = A.x, ay = A.y;
    int bx = B.x, by = B.y;
    auto half = [] (int x, int y) -> int {
        return ((y > 0 || (y == 0 && x > 0)) ? 0 : 1);
    };
    int ha = half(ax, ay), hb = half(bx, by);
    if (ha != hb) return ha > hb;
    int cross = ax * by - ay * bx;
    if (cross != 0) return cross < 0;
    int da = ax * ax + ay * ay;
    int db = bx * bx + by * by;
    return da < db;
}

void solve ()
{
    int n, q; cin >> n >> q;
    vector <point> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
        v[i].id = i + 1;
    }
    sort(v.begin(), v.end(), cmp);

    vector <int> pos(n + 1);
    for (int i = 0; i < n; i++) pos[v[i].id] = i;

    vector <int> s(n + 1, -1);
    vector <int> sz;

    int l = 0;
    int cur = 0;
    while (l < n) {
        int r = l;
        while (r + 1 < n) {
            int cross = v[l].x * v[r + 1].y - v[l].y * v[r + 1].x;
            int dot = v[l].x * v[r + 1].x + v[l].y * v[r + 1].y;
            if (cross == 0 && dot > 0) r++;
            else break;
        }
        sz.push_back(r - l + 1);
        for (int i = l; i <= r; i++) {
            s[v[i].id] = cur;
        }
        l = r + 1;
        cur++;
    }

    int m = sz.size();
    vector <int> pre(m + 1, 0);
    for (int i = 0; i < m; i++) {
        pre[i + 1] = pre[i] + sz[i];
    }

    while (q--) {
        int a, b; cin >> a >> b;
        if (s[a] == s[b]) {
            cout << sz[s[a]] << '\n';
        } else {
            if (s[a] <= s[b]) {
                cout << pre[s[b] + 1] - pre[s[a]] << '\n';
            }else {
                cout << n + pre[s[b] + 1] - pre[s[a]] << '\n';
            }
        }
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