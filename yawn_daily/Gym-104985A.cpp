#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using ld = long double;

void solve ()
{s
    int n;
    cin >> n;
    vector <array <i64, 3> > v(n + 1);
    i64 sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
        sum += v[i][0];
        v[i][2] = i;
    }

    sort(v.begin() + 1, v.end(), [] (auto a, auto b) {
        return a[1] < b[1];
    });

    vector <ld> ans(n + 1);
    ld res = 0.0;
    i64 cur = sum;

    for (int i = 1; i <= n; i++) {
        res += (ld)(v[i][1] - v[i - 1][1]) * cur / sum;
        ans[v[i][2]] = res;
        cur -= v[i][0];
    }

    cout << fixed << setprecision(15);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
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