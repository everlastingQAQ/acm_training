#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    i64 cur = x;
    bool ok = false;
    i64 t = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L') cur--;
        else cur++;
        if (cur == 0) {
            t = i;
            ok = true;
            break;
        }
    }

    if (!ok) {
        cout << 0 << '\n';
        return;
    }

    bool ok2 = false;
    i64 tt = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L') cur--;
        else cur++;
        if (cur == 0) {
            tt = i;
            ok2 = true;
            break;
        }
    }

    if (!ok2) {
        cout << 1 << '\n';
        return;
    }

    if (k < t) {
        cout << 0 << '\n';
        return;
    }

    i64 ans = 1LL + max(0LL, k - t) / tt;

    cout << ans << '\n';

}   
    
int main ()
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