#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int a, b, x;
    cin >> a >> b >> x;
    
    int ans = 1e18;
    int c = 0;
    int aa = a;

    auto cal = [&] (int y, int cc) -> void {
        int bb = b;
        int res = 1e18;
        int c = 0;
        while (bb != 0) {
            res = min(res, c + llabs(y - bb));
            bb /= x;
            c++;
        }
        res = min(res, llabs(y - bb) + c);
        ans = min(res + cc, ans);
    };  

    while (aa != 0) {
        cal(aa, c);
        aa /= x;
        c++;
    }
    cal(aa, c);

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