#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    map <int, int> mp;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        int t;
        cin >> t;
        if (mp[v[i]]) continue;
        mp[v[i]] = t;
    }

    vector <int> ans;
    for (int i = 1; i <= n; i++) {
        if (!mp[v[i]]) ans.push_back(v[i]);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    if (ans.empty()) {
        cout << "NONE";
        return;
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