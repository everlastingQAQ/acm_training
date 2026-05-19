#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] == 0) {
            ans++;
            continue;
        }
        if (v[i] == 1) {
            if (s2 >= 1) {
                ans++;
                s2--;
            }else {
                s1++;
            }
        }else {
            if (s1 >= 1) {
                ans++;
                s1--;
            }else {
                s2++;
            }
        }
    }
    while (s1 >= 3) {
        s1 -= 3;
        ans++;
    }
    while (s2 >= 3) {
        s2 -= 3;
        ans++;
    }
    cout << ans << '\n';
}

int32_t main()
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