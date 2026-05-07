#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <array <i64, 3> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0];
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i][1];
        v[i][2] = i;
    }

    sort(v.begin() + 1, v.end(), greater<>());

    i64 sum = 0;
    vector <i64> ans(n + 1);
    ans[v[1][2]] = v[1][0];
    for (int i = 2; i <= n; i++) {
        ans[v[i][2]] = min(v[1][0], v[i][1]);
        sum += min(v[1][0], v[i][1]);
    }
    
    if (v[1][0] > sum) {
        cout << -1 << '\n';
    }else {
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
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