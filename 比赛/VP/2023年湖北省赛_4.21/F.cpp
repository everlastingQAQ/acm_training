#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(2 * n + 2);
    for (int i = 1; i <= 2 * n + 2; i++) {
        cin >> v[i];
    }
    vector <char> ans(4 * n + 2, '?');
    ans[1] = '&';
    ans[2] = '|';
    ans[3] = 'a';
    int cnt1 = 0;
    for (int i = 4; i <= 2 * n + 2; i++) {
        if (i & 1) {
            if (v[i - 1] >= 3) {
                ans[i] = ans[i - 2];
            }else {
                if (ans[i - 2] == 'a') {
                    ans[i] = 'b';
                }else {
                    ans[i] = 'a';
                }
            };
        }
        if (!(i & 1)) {
            int cnt1 = v[i] / 2;
            int j = i + 1;
            int k = i - 1;
            while (cnt1--) {
                ans[j] = ans[k];
                j += 2;
                k -= 2;
            }
            if (j > i + 1) {
                i = j - 1;
            }

        }else {
            int cnt1 = (v[i] - 2) / 2;
            int j = i + 2;
            int k = i - 2;
            while (cnt1--) {
                ans[j] = ans[k];
                j += 2;
                k -= 2;
            }
            if (j > i + 2) {
                i = j - 1;
            }
        }
    }

    for (int i = 3; i <= 2 * n + 2; i += 2) {
        cout << ans[i];
    }

} 

int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 