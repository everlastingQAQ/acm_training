#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void init() 
{

}

void solve ()
{
    int n; cin >> n;
    int cnt1 = n / 3;
    int cnt2 = n / 37;
    if (n - (cnt1 + cnt2) * 3 > 0) {
        cout << "Baka!" << '\n';
        return;
    }

    deque <int> dq;
    deque <int> dqq;
    for (int i = 1; i <= n; i++) {
        if (gcd(i, 999999999) != 1) {
            dq.push_back(i);
        }else {
            dqq.push_back(i);
        }
    }

    while (dq.size() || dqq.size()) {
        if (dqq.size()) {
            cout << dqq.front() << ' ';
            dqq.pop_front(); 
        }
        if (dq.size()) {
            cout << dq.front() << ' ';
            dq.pop_front();
        }
        if (dqq.size()) {
            cout << dqq.front() << ' ';
            dqq.pop_front(); 
        }
    }
    
}   

signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}