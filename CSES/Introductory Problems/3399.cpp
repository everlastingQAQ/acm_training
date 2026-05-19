#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, a, b;
    cin >> n >> a >> b;
    if ((a + b > n) || (a == 0 && b != 0) || (a != 0 && b == 0)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector <array <int, 2> > ans;
    int t = n;
    while (a + b != t) {
        ans.push_back({t, t});
        t--;
    }
    if (a > b) {
        int l = b + 1, r = 1;
        while (a--) {
            ans.push_back({l++, r++});
        }
        l = 1;
        while (b--) {
            ans.push_back({l++, r++});
        }
    }else {
        int l = 1, r = a + 1;
        while (b--) {
            ans.push_back({l++, r++});
        }
        r = 1;
        while (a--) {
            ans.push_back({l++, r++});
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i][0] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i][1] << " \n"[i == n - 1];
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