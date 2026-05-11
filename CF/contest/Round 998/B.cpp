#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > v(n + 1, vector <int> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
        sort(v[i].begin() + 1, v[i].end());
    }
    vector <array <int, 2> > a(n + 1);

    for (int i = 1; i <= n; i++) {
        a[i][0] = v[i][1];
        a[i][1] = i;
    }
    sort(a.begin() + 1, a.end());

    vector <int> ans;
    for (int i = 1; i <= n; i++) {
        ans.push_back(a[i][1]);
    }

    vector <int> b;
    for (int j = 1; j <= m; j++) {
        for (auto x : ans) {
            b.push_back(v[x][j]);
        }
    }

    if (is_sorted(b.begin(), b.end())) {
        for (auto x : ans) {
            cout << x << " \n"[x == ans.back()];
        }
    }else {
        cout << "-1\n";
    }
} 
    
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 