#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct node {
    int a, b, c;
    string s;
};  

void solve ()
{
    int n;
    cin >> n;
    vector <node> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].a >> v[i].b >> v[i].s >> v[i].c;
    }
    sort(v.begin(), v.end(), [] (auto aa, auto bb) {
        if (aa.a != bb.a) return aa.a < bb.a;
        else {
            if (aa.c >= 80 && bb.c >= 80) {
                return aa.b < bb.b;
            }else if (aa.c >= 80 || bb.c >= 80) {
                return aa.c > bb.c;
            }else {
                return aa.b < bb.b;
            }
        }
    });

    // for (auto [a, b, c, d] : v) {
    //     cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    // }

    vector <pair<int, string> > ans;
    map <string, int> mp;
    int idx = 0;
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (idx == n) break;
        cnt = max(i, cnt);
        vector <node> t;
        vector <node> tt;
        while (idx < n && v[idx].a <= i) {
            if (v[idx].c >= 80) tt.push_back(v[idx]);
            else t.push_back(v[idx]);
            idx++;
        }

        sort(tt.begin(), tt.end(), [] (auto x, auto y) {
            return x.b < y.b;
        });
        for (auto &x : tt) {
            ans.push_back({cnt, x.s});
            cnt++;
            mp[x.s] = true;
            while (idx < n && v[idx].a <= cnt) {
                if (v[idx].c >= 80) tt.push_back(v[idx]);
                else t.push_back(v[idx]);
                idx++;
            }
        }
        
        vector <node> bb;
        for (auto &x : t) {
            if (!mp[x.s]) bb.push_back(x);
        }
        
        sort(bb.begin(), bb.end(), [] (auto x, auto y) {
            return x.b < y.b;
        });

        for (auto &p : bb) {
            if (!mp[p.s] && p.b == cnt) {
                ans.push_back({cnt, p.s});
                mp[p.s] = true;
                cnt++;
                break;
            }
        }

        while (1) {
            bool ok = false;
            for (auto &p : bb) {
                if (!mp[p.s] && p.b == cnt) {
                    ans.push_back({cnt, p.s});
                    mp[p.s] = true;
                    cnt++;
                    ok = true;
                    while (idx < n && v[idx].a <= cnt) {
                        if (v[idx].c >= 80) tt.push_back(v[idx]);
                        else t.push_back(v[idx]);
                        idx++;
                    }
                    break;
                }
            }
            if (ok) continue;
            for (auto &p : bb) {
                if (!mp[p.s]) {
                    ans.push_back({cnt, p.s});
                    mp[p.s] = true;
                    cnt++;
                    ok = true;
                    while (idx < n && v[idx].a <= cnt) {
                        if (v[idx].c >= 80) tt.push_back(v[idx]);
                        else t.push_back(v[idx]);
                        idx++;
                    }
                    break;
                }
            }

        }
        
    }

    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
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