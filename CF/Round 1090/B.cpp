#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    vector <int> v(8);
    for (int i = 1; i <= 7; i++) {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end());
    i64 ans = 0;
    for (int i = 1; i <= 6; i++) {
        ans -= v[i];
    }
    ans += v[7];
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