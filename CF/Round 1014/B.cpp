#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    string a, b; cin >> a >> b;
    a = ' ' + a, b = ' ' + b;
    vector <int> va, vb;
    for (int i = 1; i <= n; i++) {
        if (a[i] == '1') va.push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] == '0') vb.push_back(i);
    }

    int cnta1 = 0, cnta2 = 0;
    for (auto x : va) {
        if (x & 1) cnta1++;
        else cnta2++;
    }
    int cntb1 = 0, cntb2 = 0;
    for (auto x : vb) {
        if (x & 1) cntb1++;
        else cntb2++;
    }

    if (cnta1 <= cntb2 && cnta2 <= cntb1) {
        cout << "YES" << '\n';
    }else {
        cout << "NO" << '\n';
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