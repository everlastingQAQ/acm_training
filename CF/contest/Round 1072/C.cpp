#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void solve ()
{
    int n, k; cin >> n >> k;

    if (n == k) {
        cout << 0 << '\n';
        return;
    }else if (k > n) {
        cout << -1 << '\n';
        return;
    }

    deque <array<int, 2> > dq;
    dq.push_back({n, 0});

    while (dq.size()) {
        auto [x, y] = dq.front();
        dq.pop_front();
        if (x < k) {
            break;
        }

        int t1 = x / 2;
        if (x & 1) {
            if (t1 & 1) {
                if (t1 + 1 == k || t1 == k) {
                    cout << ++y << '\n';
                    return;
                }
                if (t1 < k) {
                    break;
                }
                dq.push_back({t1, ++y});
            }else {
                t1++;
                if (t1 - 1 == k || t1 == k) {
                    cout << ++y << '\n';
                    return;
                }
                if (t1 < k) {
                    break;
                }
                dq.push_back({t1, ++y});
            }
        }else {
            if (t1 == k) {
                cout << ++y << '\n';
                return;
            }
            if (t1 < k) {
                break;
            }
            dq.push_back({t1, ++y});
        }
    }

    cout << -1 << '\n';
}   
    
signed main ()
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