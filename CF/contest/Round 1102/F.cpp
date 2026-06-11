#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int st = 1;
    for (int i = 1; i <= n; i++) {
        if (v[i] > v[st]) {
            st = i;
        }
    }

    vector <array <int, 2> > a(n + 1);
    for (int i = 1; i <= n; i++) {
        int pos = (st + i - 1) % n + 1;
        a[i][0] = pos;
        a[i][1] = v[pos];
    }

    vector <int> ans(n + 1);
    vector <array <int, 2> > stk;
    int cur = 0;

    for (int i = 1; i < n; i++) {
        int cnt = 1;
        while (!stk.empty() && stk.back()[0] <= a[i][1]) {
            auto [x, y] = stk.back();
            stk.pop_back();
            cur -= x * y;
            cnt += y;
        }
        cur += a[i][1] * cnt;
        stk.push_back({a[i][1], cnt});
        ans[a[i + 1][0]] += cur;
    }

    cur = 0;
    stk.clear();

    for (int i = n - 1; i >= 1; i--) {
        int cnt = 1;
        while (!stk.empty() && stk.back()[0] <= a[i][1]) {
            auto [x, y] = stk.back();
            stk.pop_back();
            cur -= x * y;
            cnt += y;
        }
        cur += a[i][1] * cnt;
        stk.push_back({a[i][1], cnt});
        ans[a[i][0]] += cur;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
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