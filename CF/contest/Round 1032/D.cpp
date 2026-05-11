#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector <array <int, 2> > ans;
    
    auto cal = [&] (int t, vector <int> &v) -> void {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < n; j++) {
                if (v[j] > v[j + 1]) {
                    ans.push_back({t, j});
                    swap(v[j], v[j + 1]);
                }
            }
        }
    };

    cal(1, a);
    cal(2, b);

    for (int i = 1; i <= n; i++) {
        if (a[i] > b[i]) {
            ans.push_back({3, i});
        }
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
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