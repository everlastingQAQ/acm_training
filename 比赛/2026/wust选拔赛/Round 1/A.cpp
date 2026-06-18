#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> a(n + 1), b(n + 1);
    map <int, int> mpa, mpb;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mpa[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        mpb[b[i]]++;
    }

    int a1 = 0, a2 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) a1++;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i] && mpb[a[i]]) {
            a2++;
        }
    }

    cout << a1 << '\n' << a2 << '\n';
}

int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}