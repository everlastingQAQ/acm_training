#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    int cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt5 = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] == 0) cnt0++;
        if (v[i] == 1) cnt1++;
        if (v[i] == 2) cnt2++;
        if (v[i] == 3) cnt3++;
        if (v[i] == 5) cnt5++;
        if (cnt0 >= 3 && cnt1 >= 1 && cnt2 >= 2 && cnt3 >= 1 & cnt5 >= 1) {
            cout << i << '\n';
            return;
        }
    }

    cout << 0 << '\n';
}   
    
signed main ()
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