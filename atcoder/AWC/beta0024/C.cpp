#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    vector <vector <int> > vis(n + 1, vector <int> (m + 1, 0));
    for (int i = 1; i <= n; i++) {
        vector <int> vis1(30);
        for (int j = 1; j <= m; j++) {
            vis1[v[i][j] - 'a']++;
        }
        for (int j = 1; j <= m; j++) {
            if (vis1[v[i][j] - 'a'] >= 2) vis[i][j] = true;
        }
    }

    for (int j = 1; j <= m; j++) {
        vector <int> vis1(30);
        for (int i = 1; i <= n; i++) {
            vis1[v[i][j] - 'a']++;
        }
        for (int i = 1; i <= n; i++) {
            if (vis1[v[i][j] - 'a'] >= 2) vis[i][j] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j]) {
                cout << v[i][j];
            } 
        }
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