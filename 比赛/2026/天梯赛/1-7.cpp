#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    int sum = 0;
    int mx = -1;
    int mn = 1e8;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
    }
    int ave = sum / n;
    cout << mx << ' ' << mn << ' ' << ave << '\n';
    vector <int> ans;
    for (int i = 1; i <= n; i++) {
        if (v[i] > ave * 2) {
            ans.push_back(i);
        }
    }
    if (ans.size() == 0) {
        cout << "Normal";
    }else {
        for (auto x : ans) {
            cout << x << " \n"[x == ans.back()];
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