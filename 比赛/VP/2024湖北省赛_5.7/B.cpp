#include <bits/stdc++.h>
using namespace std;
#define int long long
using ld = long double;

const ld INF = 1e18;

struct point {
    int x, y;
};

void solve ()
{
    int n;
    cin >> n;
    vector <point> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].x >> v[i].y;
    }

    ld ans = INF;
    bool ok = false;

    auto cal = [&] (point a, point b) -> ld {
        return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    };

    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            for (int k = j + 1; k <= n; k++) {  
                int tx = (v[j].y - v[i].y) * (v[k].x - v[j].x);
                int ty = (v[k].y - v[j].y) * (v[j].x - v[i].x);
                if (tx == ty) continue;
                ok = true;  
                
                ld a = cal(v[i], v[j]);
                ld b = cal(v[i], v[k]);
                ld c = cal(v[j], v[k]);
                ld p = (a + b + c) / 2.0;

                ld cur = sqrtl(p * (p - a) * (p - b) * (p - c));
                ans = min(ans, cur);
            }   
        }
    }

    if (!ok) {
        cout << -1 << '\n';
    }else {
        cout << fixed << setprecision(12);
        cout << ans << '\n';
    }
    
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