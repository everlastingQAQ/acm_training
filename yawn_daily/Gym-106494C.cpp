#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> a, b;
    for (int i = 1; i <= n; i++) {
        i64 t;
        cin >> t;
        if (t >= 0) a.push_back(t);
        else b.push_back(t);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    i64 ans = 0;
    for (auto x : a) {
        ans += x;
    }
    int cnt = a.size();
    while (cnt-- && !b.empty()) {
        b.pop_back();
    }
    if (b.size()) ans += b[(b.size() - 1) / 2];
    cout << ans << '\n';
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