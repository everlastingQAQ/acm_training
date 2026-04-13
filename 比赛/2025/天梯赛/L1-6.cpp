#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l1;
            cin >> l1;
            vector <int> a(l1);
            for (int i = 0; i < l1; i++) {
                cin >> a[i];
            }
            int l2;
            cin >> l2;
            vector <int> b(l2);
            for (int i = 0; i < l2; i++) {
                cin >> b[i];
            }
            vector <int> t;
            for (int i = 0; i < v.size(); i++) {
                if (i + l1 > v.size()) break;
                bool ok = true;
                for (int j = 0; j < l1; j++) {
                    // cout << v[i + j] << ' ' << a[j] << ' ' << i << '\n';
                    if (v[i + j] != a[j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    t.push_back(i);
                    break;
                }
            }
            // cout << t.size() << '\n';
            // cout << t << '\n';
            if (t.empty()) continue;
            int cnt = 0;
            vector <int> vv;
            // cout << v.size() << '\n';
            for (int i = 0; i < v.size(); i++) {
                // cout << cnt << ' ' << t.size() << ' ' << i << ' ' << v[i] << '\n';
                if (cnt >= t.size()) {
                    // cout << "999: " << i << ' ' << v[i] << '\n';
                    vv.push_back(v[i]);
                    continue;
                }
                if (i == t[cnt]) {
                    for (int j = 0; j < l2; j++) {
                        // cout << "b[j]: " << b[j] << '\n';
                        vv.push_back(b[j]);
                    }
                    i = t[cnt] + l1 - 1;
                    // cout << i << '\n';
                    cnt++;
                }else {
                    vv.push_back(v[i]);
                }
            }
            v = vv;
        }else if (op == 2) {
            vector <int> vv;
            if (!v.empty()) vv.push_back(v[0]);
            for (int i = 1; i < v.size(); i++) {
                if (!((v[i - 1] + v[i]) & 1)) {
                    vv.push_back((v[i - 1] + v[i]) / 2);
                }
                vv.push_back(v[i]);
            }
            v = vv;
        }else if (op == 3) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            reverse(v.begin() + l, v.begin() + r + 1);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (i < v.size() - 1) cout << v[i] << ' ';
        else cout << v[i];
    }
}   
    
int main ()
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