#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n; 
    while (cin >> n) {
        if (n == 0) break;
        int mnx = 0, mxx = 1e11;
        int mny = 0, mxy = 1e11;
        int mnz = 0, mxz = 1e11;

        for (int i = 0; i < n; i++) {
            int x, y, z, l; cin >> x >> y >> z >> l;
            mnx = max(mnx, x), mxx = min(mxx, x + l);
            mny = max(mny, y), mxy = min(mxy, y + l);
            mnz = max(mnz, z), mxz = min(mxz, z + l);
        }

        cout << max(0LL, (mxx - mnx) * (mxy - mny) * (mxz - mnz)) << '\n';
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