#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct p {
    i64 x, y;
};

void solve ()
{
    int n;
    cin >> n;
    i64 umn = 0, umx = 0, vmn = 0, vmx = 0;
    i64 ans = 0;

    for (int i = 1; i <= n; i++) {
        i64 x, y;
        cin >> x >> y;
        i64 u = x + y;
        i64 v = x - y;
        umn = min(umn, u);
        umx = max(umx, u);
        vmn = min(vmn, v);
        vmx = max(vmx, v);
        ans = max({umx - umn, vmx - vmn, ans});
        
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