#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n; cin >> n;
    deque <int> dq;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        dq.push_back(t);
    }

    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            if (dq.back() > dq.front()) {
                cout << "R";
                dq.pop_back();
            }else {
                cout << "L";
                dq.pop_front();
            }
        }else {
            if (dq.back() < dq.front()) {
                cout << "R";
                dq.pop_back();
            }else {
                cout << "L";
                dq.pop_front();
            }
        }
    }
    cout << '\n';
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