#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, h;
    cin >> n >> h;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    int l = 0, r = n;

    auto check = [&] (int md) -> bool {
        vector <int> a(md + 1);
        for (int i = 1; i <= md; i++) {
            a[i] = v[i];
        }
        sort(a.begin() + 1, a.end(), greater<>());

        int sum = 0;
        for (int i = 1; i <= md; i += 2) {
            sum += a[i];
        }
        return sum <= h;
    };

    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (check(mid)) {
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }

    cout << r << '\n';
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