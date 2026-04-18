#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, t;
    cin >> n >> t;
    vector <array <int, 2> > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0];
        v[i][1] = i + 1;
    }
    vector <array <int, 2> > a;
    vector <int> ans;
    vector <int> vis(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (v[i][0] > t) a.push_back({v[i][0], v[i][1]});
        else {
            ans.push_back(v[i][1]);
            vis[v[i][1]] = 1;
        } 
    }
    // int cnt = 0;
    while (1) {
        int sum = 0;
        for (int i = a.size() - 1; i >= 0; i--) {
            sum += a[i][0];
        }
        if (a.size() == 0) break;
        sum /= a.size();
        
        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i][0] <= sum) {
                ans.push_back(a[i][1]);
                vis[a[i][1]] = true;
            }
        }

        vector <array <int, 2> > aa;
        for (int i = a.size() - 1; i >= 0; i--) {
            if (!vis[a[i][1]]) {
                aa.push_back({a[i][0], a[i][1]});
            }
        }
        if (aa.empty()) break;
        a = aa;
        // if (++cnt == 5) break;
    }
    for (auto x : ans) {
        cout << x << " \n"[x == ans.back()];
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