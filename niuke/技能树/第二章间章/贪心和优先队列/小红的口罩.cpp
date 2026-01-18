#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, k; cin >> n >> k;
    priority_queue<int, vector <int>, greater<int> > pq;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        pq.push(t);
    }

    int sum = 0;
    int day = 0;

    while (sum <= k) {
        int t = pq.top();
        pq.pop();
        sum += t;
        t *= 2;
        pq.push(t);
        day++;
    }

    cout << day - 1 << '\n';
}   
    
signed main ()
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