#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, s, d, hp;
    cin >> n >> s >> d >> hp;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        int t = b / d;
        if (d * t != b) t++;
        if (hp - min(a, 3LL) * s <= 0) {
            cout << "Yes\n";
            cout << i << '\n';
            return;
        }
        if (t > min(3LL, (5 - a))) {
            cout << "No\n";
            return;
        }
        hp -= min(a, (3 - t)) * s;
        if (hp <= 0) {
            cout << "Yes\n";
            cout << i << '\n';
            return;
        }
    }
    cout << "No\n";
}   
    
int32_t main ()
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