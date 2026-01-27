#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    vector <int> a, b;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        if (t & 1) a.push_back(t);
        else b.push_back(t);
    }

    if (a.empty()) {
        cout << ranges::max(b) << '\n';
        return;
    }else if (b.empty()) {
        cout << ranges::max(a) << '\n';
        return;
    }

    int m1 = a.size(), m2 = b.size();

    cout << accumulate(a.begin(), a.end(), -m1) + 1 + accumulate(b.begin(), b.end(), 0LL) << '\n';

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