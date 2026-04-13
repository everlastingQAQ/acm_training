#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct point {
    int x, y;
};

unordered_set<int> vis;

void solve ()
{
    int n;
    cin >> n;
    vector <point> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
    }

    vector <int> a, b, c;
    int d = 2e6;
    
    for (int i = 0; i < n; i++) {
        if (v[i].y == 0) {
            a.push_back(v[i].x);
        }else if (v[i].y == 1) {
            b.push_back(v[i].x);
        }else {
            c.push_back(v[i].x);
            vis.insert(v[i].x);
        }
    }
    
    vector <array <int, 3> > ans;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (vis.count(2 * (b[j] - a[i]) + a[i])) {
                ans.push_back({a[i], b[j], 2 * (b[j] - a[i]) + a[i]});
            }
        }
    }

    if (ans.empty()) {
        cout << "-1";
        return;
    }

    sort(ans.begin(), ans.end(), [] (auto a, auto b) {
        if (a[1] != b[1]) return a[1] < b[1];
        else if (a[0] != b[0]) return a[0] < b[0];
        else return a[2] < b[2];
    });
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << "[" << ans[i][0] << ',' << " 0] ";
        cout << "[" << ans[i][1] << ',' << " 1] ";
        if (i < ans.size() - 1) cout << "[" << ans[i][2] << ',' << " 2]\n";
        else cout << "[" << ans[i][2] << ',' << " 2]";
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