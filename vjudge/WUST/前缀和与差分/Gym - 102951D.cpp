#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct node {
    int l, r;
    i64 v;
};

void solve ()
{
    int n, q;
    cin >> n >> q;
    vector <node> a(n + 1);
    vector <int> xs;
    xs.reserve(2 * (n + q));
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].v;
        xs.push_back(a[i].l);
        xs.push_back(a[i].r);
    }
    vector <array <int, 2> > b(q);
    for (int i = 0; i < q; i++) {
        cin >> b[i][0] >> b[i][1];
        xs.push_back(b[i][0]);
        xs.push_back(b[i][1]);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    int m = xs.size();
    vector <i64> d(m + 1);

    auto id = [&] (int x) {
        return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    };
    
    for (auto [l, r, v] : a) {
        d[id(l)] += v;
        d[id(r)] -= v;
    }

    vector <i64> pre(m);
    i64 cur = 0;
    for (int i = 0; i < m - 1; i++) {
        cur += d[i];
        pre[i + 1] = pre[i] + cur * (xs[i + 1] - xs[i]);
    }   

    for (auto [l, r] : b) {
        cout << pre[id(r)] - pre[id(l)] << '\n';
    }
}

int main ()
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