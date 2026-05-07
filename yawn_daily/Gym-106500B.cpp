#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    int l = n - 1, r = n * 2 - 1;
    vector <int> v;
    int cnt = 0;
    while (r > n) {
        while (r > n && r >= 2 * l) {
            r--;
            cnt++;
        }
        v.push_back(cnt);
        l--;
    }
    i64 ans = 1;
    cnt = 0;
    for (auto x : v) {
        ans *= (x - cnt);
        cnt++;
    }
    while (n - cnt - 1 >= 1) {
        ans *= (n - cnt - 1);
        cnt++;
    }
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