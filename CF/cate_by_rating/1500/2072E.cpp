#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector <i64> a;

void init ()
{
    int cur = 0;
    for (int i = 1; cur <= 1e5; i++) {
        cur += i;
        a.push_back(cur);
    }
}

void solve ()
{
    int n;
    cin >> n;
    vector <int> ans;
    int sum = 0;
    while (n > 0) {
        int cnt = upper_bound(a.begin(), a.end(), n) - a.begin() - 1;
        sum += cnt + 2;
        ans.push_back(cnt + 2);
        n -= a[cnt];
    }
    cout << sum << '\n';
    int x = -1e9;
    int y = -1e9;
    for (auto cnt : ans) {
        for (int i = 1; i <= cnt; i++) {
            cout << x << ' ' << y << '\n';
            x++;
        }
        y++;
    }
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
} 