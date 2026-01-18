#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    string s; cin >> s;
    vector <int> v(n);
    int cnt0 = 0;
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') v[i] == 0, cnt0++;
        else v[i] = 1, cnt1++;
    }

    vector <int> a;
    a = v;
    ranges::sort(a);
    
    if (a == v) {
        cout << "Bob" << '\n';
    }else {
        cout << "Alice" << '\n';
        int cnt = 0;
        vector <int> b;
        for (int i = 0; i < cnt0; i++) {
            if (v[i] == 1) b.push_back(i);
        }
        for (int i = cnt0; i < n; i++) {
            if (v[i] == 0) b.push_back(i);
        }
        cout << b.size() << '\n';
        for (auto x : b) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
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