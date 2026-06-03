#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, q;
    cin >> n >> q;
    vector <int> v(n + 1);
    map <int, int> cnt;
    int mn = 0;
    while (q--) {
        int op, t;
        cin >> op >> t;
        if (op == 1) {
            int x = v[t];
            cnt[x + 1]++;
            v[t]++;
            if (x == mn && cnt[x + 1] == n) {
                mn++;
            }
        }else {
            cout << cnt[t + mn] << '\n';
        }
    }
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