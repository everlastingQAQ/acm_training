#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <int> cnt(26);
    for (auto c : s) {
        cnt[c - 'a']++;
    }

    auto check = [&] (int md) -> bool {
        int cur = 0;
        int y = 0;
        for (auto x : cnt) {
            cur += 2 * (x / 2);
            if (x & 1) y++;
        }
        if (md & 1) {
            int mx = cur + min(y, k);
            return mx >= k * md;
        }else {
            return cur >= k * md;
        }
    };

    int l = 1, r = n / k;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (check(mid)) {
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }

    cout << r << '\n';
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