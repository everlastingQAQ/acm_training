#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, x;
    cin >> n >> x;
    vector <i64> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    i64 t = 0;
    i64 mn = 1e13;
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        t -= a[i];
        if (t < mn) {
            mn = t;
            pos = i;
        }
        t += b[i];
    }
    // cout << pos << '\n';

    i64 cur = x;
    int cnt = 0;
    bool found = false;
    for (int i = 1; i <= pos; i++) {
        cur -= a[i];
        if (cur < 0) {
            found = true;
            break;
        }
        cur += b[i];
        cnt++;
    }
    if (found) {
        cout << cnt << '\n';
        return;
    }

    i64 init = cur;
    // cout << init << '\n';

    for (int i = pos + 1; i <= n; i++) {
        cur -= a[i];
        if (cur < 0) {
            found = true;
            break;
        }
        cur += b[i];
        cnt++;
    }
    if (found) {
        cout << cnt << '\n';
        return;
    }

    for (int i = 1; i <= pos; i++) {
        cur -= a[i];
        if (cur < 0) {
            found = true;
            break;
        }
        cur += b[i];
        cnt++;
    }
    if (found) {
        cout << cnt << '\n';
        return;
    }

    i64 diff = init - cur;
    if (cur >= init) {
        cout << "Infinity\n";
        return;
    }

    i64 base = cnt;

    i64 count = (cur - mn) / diff - 5;
    if (count - 5 < 0) {
        count = 0;
    }
    cur -= count * diff;
    // cout << cur << '\n';
    i64 bonus = 0;

    while (cur > 0) {
        found = true;
        for (int i = pos + 1; i <= n; i++) {
            cur -= a[i];
            if (cur < 0) {
                found = false;
                break;
            }
            cur += b[i];
            bonus++;
        }   
        if (!found) {
            break;
        }
        for (int i = 1; i <= pos; i++) {
            cur -= a[i];
            if (cur < 0) {
                found = false;
                break;
            }
            cur += b[i];
            bonus++;
        }
        if (!found) {
            break;
        }
    }

    cout << base + count * n + bonus << '\n';
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