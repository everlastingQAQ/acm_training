#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    priority_queue <i64, vector <i64>, greater<i64> > pq;
    for (int i = 1; i <= n; i++) {
        i64 t;
        cin >> t;
        pq.push(t);
    }
    
    i64 ans = 0;
    while (pq.size() > 1) {
        i64 a = pq.top();
        pq.pop();
        i64 b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }

    cout << ans << '\n';
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