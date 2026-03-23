#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    string s;
    cin >> s;
    int n = s.size();
    int lo = 0, ri = n - 1;
    while (s[lo] == s[ri] && lo <= ri) {
        s.erase(s.begin());
        s.erase(s.end());
        lo++;
        ri--;
    }

    n = s.size();
    int ans = 1e11;

    auto cal = [&] (string s) -> void {
        int res = -1;
        int l = 0, r = n;

        auto check = [&] (int md) -> bool {
            vector <int> cnt(26, 0);
            for (int i = 0; i < md; i++) {
                cnt[s[i] - 'a']++;
            }
            for (int i = 0; i < min(n / 2, n - md); i++) {
                char c = s[n - i - 1];
                cnt[c - 'a']--;
            }
            
        };

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                res = mid;
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }

        ans = min(ans, res);
    };
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