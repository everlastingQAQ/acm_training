#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i32 = int;

void solve ()
{
    i32 n, w;
    cin >> n >> w;
    priority_queue <tuple <long double, i64, i64> > pq;
    for (int i = 1; i <= n; i++) {
        i64 a, b;
        cin >> a >> b;
        long double t = sqrtl(a * a + b * b) - sqrtl(a * a + (b - 1) * (b - 1));
        pq.push({t, a, b});
    }

    long double ans = 0;
    while (pq.size() && w--) {
        auto [val, a, b] = pq.top();
        pq.pop();
        b--;
        if (b == 0) {
            ans += sqrtl(a * a + b * b);
            continue;
        }
        long double t = sqrtl(a * a + b * b) - sqrtl(a * a + (b - 1) * (b - 1));
        pq.push({t, a, b});
    }

    while (pq.size()) {
        auto [val, a, b] = pq.top();
        pq.pop();
        ans += sqrtl(a * a + b * b);
    }

    cout << fixed << setprecision(10) << ans << '\n';
}   
    
int main ()
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