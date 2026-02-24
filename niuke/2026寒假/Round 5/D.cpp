#include <bits/stdc++.h>
using namespace std;
#define int long long

priority_queue <array <int, 2>, vector <array <int, 2> >, greater<array <int, 2> > > pq;

const int mod = 1e9 + 7;

void solve ()
{
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        int c, w;
        cin >> c >> w;
        pq.push({w, c});
    }

    int ans = 0;
    while (pq.size() > 1 || pq.size() && pq.top()[1] > 1) {
        auto [w, c] = pq.top();
        pq.pop();
        if (c <= 0) continue;
        if (!(c & 1)) {
            pq.push({w * 2, c / 2});
            ans = (ans + (w % mod * c % mod) % mod) % mod;
        }else {
            if (c > 1) {
                pq.push({w * 2, c / 2});
                ans = (ans + (w % mod * (c - 1) % mod) % mod) % mod;
            }
            if (pq.empty()) break;
            auto [w1, c1] = pq.top();
            pq.pop();
            pq.push({w1 + w, 1});
            if (c1 - 1 > 0) pq.push({w1, c1 - 1});
            ans = (ans + (w + w1) % mod) % mod;
        }
    }

    cout << ans % mod;
    
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/