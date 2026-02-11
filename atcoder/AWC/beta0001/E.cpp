#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    deque <int> dq0, dq1;
    int ans = -1e11;

    for (int i = 1; i <= n; i++) {
        while (dq0.size() && v[dq0.back()] >= v[i]) {
            dq0.pop_back();
        }
        dq0.push_back(i);
        while (dq1.size() && v[dq1.back()] <= v[i]) {
            dq1.pop_back();
        }
        dq1.push_back(i);
        if (i - k < 0) continue;

        while (dq0.front() < i - k + 1) {
            dq0.pop_front();
        }
        while (dq1.front() < i - k + 1) {
            dq1.pop_front();
        }

        ans = max(ans, v[dq1.front()] - v[dq0.front()]);
    }

    cout << ans << '\n';
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