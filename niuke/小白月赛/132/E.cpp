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
    vector <int> pre(n + 1), suf(n + 1);
    vector <int> stk;
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && v[stk.back()] <= v[i]) {
            stk.pop_back();
        }
        if (!stk.empty()) {
            pre[i] = stk.back();
        }else {
            pre[i] = 0;
        }
        stk.push_back(i);
    }

    stk.clear();
    for (int i = n; i >= 1; i--) {
        while (!stk.empty() && v[stk.back()] <= v[i]) {
            stk.pop_back();
        }
        if (!stk.empty()) {
            suf[i] = stk.back();
        }else {
            suf[i] = n + 1;
        }
        stk.push_back(i);
    }
    
    for (int i = 1; i <= n; i++) {
        int a1 = (i - pre[i]) * (n - i + 1);
        int a2 = (suf[i] - i) * i;
        int a3 = (i - pre[i]) * (suf[i] - i);
        cout << a1 + a2 - a3 << " \n"[i == n];
    }
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