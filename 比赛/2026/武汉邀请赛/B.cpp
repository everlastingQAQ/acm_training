#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> v(n + 1);
    bool ok3 = true;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] != v[1]) {
            ok3 = false;
        }
    }
    vector <int> c(m + 1), x(m + 1);
    int c0 = 0, cg = 0, cm = 0;
    bool ok1 = false, ok2 = false;
    for (int i = 1; i <= m; i++) {
        cin >> c[i] >> x[i];
        if (c[i] == 0) c0++;
        else if (c[i] == 1) cm++;
        else cg++;
        if (ok1 && (c[i] == 1 || c[i] == 0)) {
            ok2 = true;
        }
        if (c[i] == 0 || c[i] == 2) {
            ok1 = true;
        }
    }
    if (ok2 || ok3) {
        cout << "Yes\n";
        return;
    }

    if (c0 == 1) {
        if (c[m] == 0) {
            vector <int> a(n + 1);
            if (m >= 2) {
                for (int i = 1; i <= n; i++) {
                    if (v[i] == 0) {
                        if ((m - 2) & 1) {
                            if (x[m - 1] == 1) {
                                a[i] = 2;
                            }else {
                                a[i] = 1;
                            }
                        }else {
                            a[i] = 0;
                        }
                    }else {
                        if ((m - 2) & 1) {
                            a[i] = 0;
                        }else {
                            if (x[m - 1] == 1) {
                                a[i] = 2;
                            }else {
                                a[i] = 1;
                            }
                        }
                    }
                }
            }else a = v;

            bool ok = true;
            int t = gcd(a[1], x[m]);
            for (int i = 1; i <= n; i++) {
                if (gcd(a[i], x[m]) != t) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "Yes\n";
                return;
            }

            ok = true;
            for (int i = 1; i <= n; i++) {
                if (a[i] == 0) {
                    if (x[m] == 1) {
                        a[i] = 2;
                    }else {
                        a[i] = 1;
                    }
                }else {
                    a[i] = 0;
                }
            }
            for (int i = 1; i <= n; i++) {
                if (a[i] != a[1]) {
                    ok = false;
                }
            }
            cout << (ok ? "Yes\n" : "No\n");
        }else {
            int p = m + 1;
            for (int i = 1; i <= m; i++) {
                if (c[i] == 0) {
                    p = i;
                    break;
                }
            }

            vector <int> a(n + 1);
            if (p != 1) {
                for (int i = 1; i <= n; i++) {
                    if (v[i] == 0) {
                        if ((p - 1) & 1) {
                            if (x[p - 1] == 1) {
                                a[i] = 2;
                            }else {
                                a[i] = 1;
                            }
                        }else {
                            a[i] = 0;
                        }
                    }else {
                        if ((p - 1) & 1) {
                            a[i] = 0;
                        }else {
                            if (x[p - 1] == 1) {
                                a[i] = 2;
                            }else {
                                a[i] = 1;
                            }
                        }
                    }
                }
            }else a = v;

            //mex
            vector <int> b;
            b = a;
            bool ok = true;
            for (int i = 1; i <= n; i++) {
                if (a[i] == 0) {
                    if (x[p] == 1) {
                        a[i] = 2;
                    }else {
                        a[i] = 1;
                    }
                }else {
                    a[i] = 0;
                }
            }
            
            if (c[p + 1] == 1) {
                for (int i = p + 1; i <= n; i++) {
                    if (a[i] == 0) {
                        if ((n - p) & 1) {
                            if (x[p - 1] == 1) {
                                a[i] = 2;
                            }else {
                                a[i] = 1;
                            }
                        }else {
                            a[i] = 0;
                        }
                    }else {
                        if ((n - p) & 1) {
                            a[i] = 0;
                        }else {
                            if (x[p - 1] == 1) {
                                a[i] = 2;
                            }else {
                                a[i] = 1;
                            }
                        }
                    }
                }
            }else {
                int t = 0;
                for (int i = p + 1; i <= m; i++) {
                    t = gcd(t, x[i]);
                }
                for (int i = 1; i <= n; i++) {
                    a[i] = gcd(a[i], t);
                }
            }
            for (int i = 1; i <= n; i++) {
                if (a[i] != a[1]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "Yes\n";
                return;
            }
            ok = true;

            //gcd
            a = b;
            for (int i = 1; i <= n; i++) {
                a[i] = gcd(a[i], x[p]);
            }
            int t = 0;
            for (int i = p + 1; i <= m; i++) {
                t = gcd(t, x[i]);
            }
            for (int i = 1; i <= n; i++) {
                a[i] = gcd(a[i], t);
            }
            for (int i = 1; i <= n; i++) {
                if (a[i] != a[1]) {
                    ok = false;
                    break;
                }
            }
            cout << (ok ? "Yes\n" : "No\n");
        }
    }else {
        int p = m + 1;
        for (int i = 1; i <= m; i++) {
            if (c[i] == 2) {
                p = i;
                break;
            }
        }

        if (p == m + 1) {
            for (int i = 1; i <= n; i++) {
                if (v[i] == 0) {
                    if ((p - 2) & 1) {
                        if (x[p - 1] == 1) {
                            v[i] = 2;
                        }else {
                            v[i] = 1;
                        }
                    }else {
                        v[i] = 0;
                    }
                }else {
                    if ((p - 2) & 1) {
                        v[i] = 0;
                    }else {
                        if (x[p - 1] == 1) {
                            v[i] = 2;
                        }else {
                            v[i] = 1;
                        }
                    }
                }
            }
        }else if (p == 1) {
            int t = 0;
            for (int i = p; i <= m; i++) {
                t = gcd(t, x[i]);
            }
            for (int i = 1; i <= n; i++) {
                v[i] = gcd(v[i], t);
            }
        }else {
            for (int i = 1; i <= n; i++) {
                if (v[i] == 0) {
                    if ((p - 2) & 1) {
                        if (x[p - 1] == 1) {
                            v[i] = 2;
                        }else {
                            v[i] = 1;
                        }
                    }else {
                        v[i] = 0;
                    }
                }else {
                    if ((p - 2) & 1) {
                        v[i] = 0;
                    }else {
                        if (x[p - 1] == 1) {
                            v[i] = 2;
                        }else {
                            v[i] = 1;
                        }
                    }
                }
            }
            int t = 0;
            for (int i = p; i <= m; i++) {
                t = gcd(t, x[i]);
            }
            for (int i = 1; i <= n; i++) {
                v[i] = gcd(v[i], t);
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (v[i] != v[1]) {
                cout << "No\n";
                return;
            }
        }
        
        cout << "Yes\n";
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