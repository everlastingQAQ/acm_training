#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    cout << 1 << ' ' << 1 << ' ' << n << endl;
    int s1, s2;
    cin >> s1;
    cout << 2 << ' ' << 1 << ' ' << n << endl;
    cin >> s2;
    i64 d = s2 - s1;
    if (d == n) {
        cout << "!" << ' ' << 1 << ' ' << n << endl;
        return;
    }

    auto check = [&] (int l, int md) -> i64 {
        i64 c1, c2;
        cout << 1 << ' ' << l << ' ' << md << endl;
        cin >> c1;
        cout << 2 << ' ' << l << ' ' << md << endl;
        cin >> c2;
        if (c1 == c2) {
            return -2;
        }else if (c2 - c1 == d) {
            if (md - l + 1 == d) {
                return c2 - c1;
            }else {
                return -1;
            }
        }else {
            i64 t = c2 - c1;
            return t;
        }
    };

    int lo = 1, ri = n;
    while (lo <= ri) {
        if (ri - lo + 1 == d) {
            cout << "!" << ' ' << lo << ' ' << ri << endl;
            return;
        }
        int mid = lo + (ri - lo) / 2;
        i64 t = check(lo, mid);
        if (t != -1 && t != -2) {
            i64 al = mid - t + 1;
            i64 ar = mid + (d - t);
            cout << "!" << ' ' << al << ' ' << ar << endl;
            return;
        }else if (t == -2) {
            lo = mid + 1;
        }else {
            ri = mid;
        }
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