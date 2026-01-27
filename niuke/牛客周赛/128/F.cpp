#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') v[i] = 1;
        else if (s[i] == '2') v[i] = 2;
        else if (s[i] == '0') v[i] = 0;
    }

    int l = 1, r = 1;

    vector <int> vis1(n + 1, 0);
    vector <int> vis2(n + 1, 0);
    vector <int> vis3(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (i < n && v[i] == 1 && v[i + 1] == 0) {
            vis1[i] = true;
        }else if (i < n && v[i] == 1 && v[i + 1] == 1) {
            vis2[i] = true;
        }else if (i < n && v[i] == 1 && v[i + 1] == 2) {
            vis3[i] = true;
        }
    }

    if (v[n] == 1) vis3[n] = true;

    deque <int> stk1;
    deque <int> stk2;
    deque <int> stk3;
    for (int i = 1; i <= n; i++) {
        if (vis1[i] == true) {
            stk1.push_front(i);
        }else if (vis2[i] == true) {
            stk2.push_back(i);
        }else if (vis3[i] == true) {
            stk3.push_back(i);
        }
    }

    while (stk3.size() && stk1.size()) {
        int a = stk3.back(), b = stk1.back();
        stk3.pop_back(), stk1.pop_back();
        v[a] = 2, v[b] = -1;
    }

    if (stk1.size()) {
        while (stk2.size() && stk1.size()) {
            int a = stk2.back(), b = stk1.back();
            stk2.pop_back(), stk1.pop_back();
            v[a] = 2, v[b] = -1;
        }
        while (stk1.size() >= 2) {
            int a = stk1.back(); stk1.pop_back();
            int b = stk1.back(); stk1.pop_back();
            v[a] = 2, v[b] = -1;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (v[i] == -1) continue;
        cout << v[i];
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