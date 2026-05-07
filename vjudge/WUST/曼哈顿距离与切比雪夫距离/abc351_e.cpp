#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> x1, y1, x2, y2;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        if ((x + y) & 1) {
            x1.push_back(x + y);
            y1.push_back(x - y);
        }else {
            x2.push_back(x + y);
            y2.push_back(x - y);
        }
    }
    
    auto cal = [&] (vector <i64> &v) {
        sort(v.begin(), v.end());
        int m = v.size();
        i64 res = 0;
        i64 sum = 0;
        for (int i = 0; i < m; i++) {
            res += v[i] * i - sum;
            sum += v[i];
        }
        return res;
    };

    i64 ans = cal(x1) + cal(y1) + cal(x2) + cal(y2);
    cout << ans / 2 << '\n';
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