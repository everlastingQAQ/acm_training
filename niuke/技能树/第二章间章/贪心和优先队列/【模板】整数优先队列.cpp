#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == 1) {
            int t; cin >> t;
            pq.push(t);
        }else if (a == 2) {
            if (pq.size()) {
                cout << pq.top() << '\n';
            }
        }else if (a == 3) {
            if (pq.size()) {
                pq.pop();
            }
        }
    }
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