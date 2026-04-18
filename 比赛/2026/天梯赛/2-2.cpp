#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    vector <int> a1;
    for (int i = 1; i <= n; i++) {
        if (v[i] == mx) a1.push_back(i);
    }
    for (auto x : a1) {
        cout << x << " \n"[x == a1.back()];
    }

    vector <array <int, 2> > a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i][0] = v[i];
        a[i][1] = i;
    }
    sort(a.begin() + 1, a.end(), [] (auto aa, auto bb) {
        if (aa[0] != bb[0]) return aa[0] < bb[0];
        else return aa[1] < bb[1];
    }); 

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int l = 1, r = n;
        int pos = n + 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid][0] > x) {
                pos = mid;
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        if (pos == n + 1 || a[pos][0] <= x) {
            cout << 0 << '\n';
        }else {
            cout << a[pos][1] << '\n';
        }
    }

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