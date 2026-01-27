#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6;

class DSU {
    public:
        vector <int> fa, rk;
        DSU (int n = 0) { init(n); }

        void init (int n) {
            fa.resize(n + 1);
            rk.assign(n + 1, 1);
            iota(fa.begin(), fa.end(), 0LL);
        }

        int find (int x) {
            return x == fa[x] ? x : (fa[x] = find(fa[x]));
        }

        bool merge (int i, int j) {
            int x = find(i), y = find(j);
            if (x == y) return false;
            if (rk[x] < rk[y]) swap(x, y);
            fa[y] = x;
            if (rk[x] == rk[y]) rk[x]++;
            return true;
        }
};

void solve ()
{   
    int x, y;
    while (cin >> x >> y) {
        if (x == -1 && y == -1) {
            break;
        }
        if (x == 0 && y == 0) {
            cout << "Yes" << '\n';
            continue;
        }

        vector <array<int, 2> > v;
        set <int> st;
        v.push_back({x, y});
        st.insert(x), st.insert(y);
        int c, d;
        int mx = 0, mn = 1e11;
        mx = max({mx, x, y});
        mn = min({mn, x, y});
        while (cin >> c >> d) {
            if (c == 0 && d == 0) break;
            v.push_back({c, d});
            mx = max({mx, c, d});
            mn = min({mn, c, d});
            st.insert(c), st.insert(d);
        }

        DSU dsu (mx);
        bool ok = true;
        
        for (auto [a, b] : v) {
            a = dsu.find(a), b = dsu.find(b);
            if (a == b) {
                ok = false;
                break;
            }
            dsu.merge(a, b);
        }

        int t = dsu.find(mn);

        for (auto x : st) {
            if (dsu.find(x) != t) {
                ok = false;
                break;
            }
        }

        if (ok) {
            cout << "Yes" << '\n';
        }else {
            cout << "No" << '\n';
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