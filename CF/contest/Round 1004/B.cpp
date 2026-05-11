#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        cnt[v[i]]++;
    }
    
    sort(v.begin() + 1, v.end());

    if (cnt[v[1]] & 1) {
        cout << "No\n";
        return;
    }

    vector <int> vis(n + 1, 0);
    vis[v[1]] = true;
    int cur = v[1];

    for (int i = 2; i <= n; i++) {
        if (!vis[v[i]]) {
            vis[v[i]] = true;
            if (cur != )
        }   
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