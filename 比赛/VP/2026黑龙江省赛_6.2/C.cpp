
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    int n1 = n / 3 + (n % 3 + 1) / 2;
    int n2 = n / 3 + (n % 3) / 2;
    int n3 = n / 3;

    vector <int> mn, md, mx;
    mn.reserve (n), md.reserve (n), mx.reserve (n);

    int pos = 1;
    for (int i = 1; i <= n1; i ++) {
        mn.push_back (i);
    }

    for (int i = n1 + 1; i <= n1 + 1 + n2 - 1; i ++) {
        md.push_back (i);
    }

    for (int i = n1 + n2 + 1; i <= n; i ++) {
        mx.push_back (i);
    }

    int p1 = 0, p2 = 0, p3 = 0;

    for (int i = 0; i < n / 3; i ++) {
        cout << mn[p1] << ' ' << md[p2] << ' ' << mx[p3] << ' ';
        p1 ++;
        p2++;
        p3++;
    }

    if (p1 < n1) cout << mn[p1] << ' ';
    if (p2 < n2) cout << md[p2] << ' ';

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