#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    int lo = 0, ri = ranges::max(v);

    auto check = [&] (int x) -> bool {
        bool ok = false;
        int l = 1, r = 1;
        int cnt = 0;

        while (r <= n) {
            if (s[r] == 'R' || (s[r] == 'B' && v[r] <= x)) {
                r++;
                continue;
            }

            while (r <= n) {
                r++;
                if (s[r] == 'R' && v[r] > x) {
                    break;
                }
            }
            cnt++;
            r++;

        }

        return cnt <= k;
    };

    while (lo <= ri) {
        int mid = lo + (ri - lo) / 2;
        if (check(mid)) {
            ri = mid - 1;
        }else {
            lo = mid + 1;
        }
    }

    cout << lo << '\n';
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