#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <array <int, 2> > v(n + 1);
    vector <int> xs;
    xs.reserve(2 * n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
        xs.push_back(v[i][0]);
        xs.push_back(v[i][1]);
    }
    
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    auto id = [&] (int x) -> int {
        return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    };

    vector <int> d(xs.size() + 1);
    for (int i = 1; i <= n; i++) {
        d[id(v[i][0])]++;
        d[id(v[i][1])]--;
    }

    i64 cur = 0;
    i64 ans = 0;
    for (int i = 0; i < xs.size(); i++) {
        cur += d[i];
        ans = max(ans, cur);
    }

    cout << ans << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}