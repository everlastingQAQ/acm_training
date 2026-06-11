#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    string s1, s2, s3;
    cin >> s1 >> s3;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] == s3[i]) s2 += '0';
        else s2 += '1';
    }
    
    auto cal = [&] (int &c, string s) -> void {
        int c0 = 0, c1 = 0;
        for (auto c : s) {
            if (c == '0') c0++;
            else c1++;
        }
        c = c0 * c1;
    };
    cal(c1, s1);
    cal(c2, s2);
    cal(c3, s3);

    int len = 1;
    int cc1 = 1, cc2 = 1, cc3 = 1;
    for (int i = 1; i <= k - 1; i++) {
        len *= 2;
        if (!(i & 1)) {
            cc2 += len / 3 + (len % 3 >= 1 ? 1 : 0);
            cc1 += len / 3 + (len % 3 >= 2 ? 1 : 0);
            cc3 += len / 3;
        }else {
            cc3 += len / 3 + (len % 3 >= 1 ? 1 : 0);
            cc1 += len / 3 + (len % 3 >= 2 ? 1 : 0);
            cc2 += len / 3;
        }
    }
    
    int ans = c1 * cc1 + c2 * cc2 + c3 * cc3;
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