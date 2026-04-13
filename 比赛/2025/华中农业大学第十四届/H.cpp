#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n;
    cin >> n;
    vector <i64> a(n + 1), b(n + 1);
    map <i64, i64> mpa, mpb;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mpa[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        mpb[b[i]]++;
    }

    i64 ans = 0;
    for (auto [x, y] : mpa) {
        ans += y * (y - 1) / 2;
    }
    for (auto [x, y] : mpb) {
        ans += y * (y - 1) / 2;
    }
    cout << ans << '\n';
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