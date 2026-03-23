#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, d;
    cin >> n >> d;
    vector <int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    deque <array <int, 2> > dq;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= a[i]; j++) {
            dq.push_back({1, i + d + 1});
        }
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            if (y == i) {
                dq.pop_front();
            }else {
                break;
            }
        }
        int cnt = 0;
        for (int j = 1; j <= b[i]; j++) {
            dq.pop_front();
        }
    }
    while (!dq.empty()) {
        auto [x, y] = dq.front();
        if (y == n + 1) {
            dq.pop_front();
        }else {
            break;
        }
    }

    cout << dq.size() << '\n';
} 
    
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 