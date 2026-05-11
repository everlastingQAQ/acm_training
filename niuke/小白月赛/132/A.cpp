#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(8);
    int t = 1000;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        t += x;
        if (t >= 0 && t <= 699) v[1]++;
        if (t >= 700 && t <= 1099) v[2]++;
        if (t >= 1100 && t <= 1499) v[3]++;
        if (t >= 1500 && t <= 1999) v[4]++;
        if (t >= 2000 && t <= 2399) v[5]++;
        if (t >= 2400 && t <= 2799) v[6]++;
        if (t >= 2800) v[7]++;
    }
    for (int i = 1; i <= 7; i++) {
        cout << v[i] << ' ';
    }
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