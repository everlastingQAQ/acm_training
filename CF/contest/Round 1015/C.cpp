#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    vector <int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    map <int, int> mp;
    int cnt = 0;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) cnt++, ok = true;
        if (cnt > 1) {
            cout << -1 << '\n';
            return;
        }
        if (mp[a[i]] != 0) {
            if (b[i] != mp[a[i]]) {
                cout << -1 << '\n';
                return;
            }
        }
        if (mp[b[i]] != 0) {
            if (a[i] != mp[b[i]]) {
                cout << -1 << '\n';
                return;
            }
        } 
        mp[a[i]] = b[i];
        mp[b[i]] = a[i];
    }

    if ((!(n & 1) && cnt != 0) || (n & 1 && cnt != 1)) {
        cout << -1 << '\n';
        return;
    }

    vector <int> v(n + 1);
    for (int i = 0; i < n; i++) {
        v[a[i]] = i;
    }

    vector <array <int, 2> > ans;
    if (ok) {
        for (int i = 1; i <= n; i++) {
            if (mp[i] == i && v[i] != n / 2) {
                int p = v[i], q = n / 2;
                int valp = a[p], valq = a[q];

                ans.push_back({p, q});
                swap(a[p], a[q]);
                swap(b[p], b[q]);

                v[valp] = q;
                v[valq] = p;
                break;
            }
        }
    }

    for (int i = 0; i < n / 2; i++) {
        int t = mp[a[i]];

        if (v[t] != n - i - 1) {
            // for (int x : a) cout << x << " \n"[x == a.back()];
            // for (int x : b) cout << x << " \n"[x == b.back()];
            // // cout << t << ' ' << v[t] << ' ' << i << '\n';
            // cout << '\n';
            ans.push_back({v[t], n - i - 1});
            int p = v[t], q = n - i - 1;
            int x = a[p], y = a[q];
            swap(a[v[t]], a[n - i - 1]);
            swap(b[v[t]], b[n - i - 1]);
            v[x] = q;
            v[y] = p;
            // for (int x : a) cout << x << " \n"[x == a.back()];
            // for (int x : b) cout << x << " \n"[x == b.back()];
            // swap(v[t], v[a[n - i - 1]]);
            // cout << v[t] << ' ' << v[a[n - i - 1]] << '\n';
        }
        
    }

    // for (int x : a) cout << x << " \n"[x == a.back()];
    // for (int x : b) cout << x << " \n"[x == b.back()];

    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x + 1 << ' ' << y + 1 << '\n';
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