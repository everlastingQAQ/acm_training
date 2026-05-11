#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n; cin >> n;
    string s; cin >> s; s = ' ' + s;
    vector <int> v(n + 5);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') v[i] = 0;
        else v[i] = 1, ans++;
    }
    if (ans == 0) {
        cout << (n + 2) / 3 << '\n';
        return;
    }

    vector <int> a;

    for (int i = 1; i <= n; i++) {
        if (v[i] == 1) a.push_back(i);
    }

    int m = a.size();
    // for (int i = 0; i < m; i++) {
    //     cout << a[i] << ' ';
    // }
    ans += a[0] / 3;
    ans += (n - a[m - 1] + 1) / 3;

    for (int i = 1; i < m; i++) {
        int t = a[i] - a[i - 1] - 1;
        ans += t / 3;
    }

    cout << ans << '\n';
}   
    
int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 