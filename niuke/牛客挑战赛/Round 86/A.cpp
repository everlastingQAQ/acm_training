#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s = ' ' + s;
    t = ' ' + t;
    bool ok1 = false;
    bool ok2 = false;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            ok1 = true;
        }
        if (t[i] == '1') {
            ok2 = true;
        }
    }

    if (!ok1 && ok2) {
        cout << "NO\n";
        return;
    }
 
    if (n == 2) {
        if (t == " 10") {
            if (s == " 10") {
                cout << "YES\n";
            }else {
                cout << "NO\n";
            }
        }else if (t == " 01") {
            if (s == " 01") {
                cout << "YES\n";
            }else {
                cout << "NO\n";
            }
        }else {
            cout << "YES\n";
        }
        return;
    }

    int l = 1, r = 1;
    string s1, t1;
    while (r <= n) {
        bool ok = false;
        while (r < n && s[r] == '1' && s[r + 1] == '0') {
            r += 2;
        }
        if (r - l >= 4) {
            if (s[r] == '1') {
                ok = true;
                string a, b;
                if (r > n) {
                    a = s.substr(l, r - 2);
                    b = t.substr(l, r - 2);
                }else { 
                    a = s.substr(l, r);
                    b = t.substr(l, r);
                }
                if (a != b) {
                    cout << "NO\n";
                    return;
                }else {
                    for (auto c : a) {
                        s1.push_back(c);
                    }
                    for (auto c : a) {
                        t1.push_back(c);
                    }
                }
            }
        }else {
            string a = s.substr(l, r);
            string b = t.substr(l, r);
            for (auto c : a) {
                s1.push_back(c);
            }
            for (auto c : b) {
                t1.push_back(c);
            }
        }
        if (ok) {
            if (s1.size() == 1) {
                if (s1 != t1) { 
                    cout << "NO\n";
                    return;
                }
            }else if (s1.size() == 2) {
                if (t1 == "10") {
                    if (s1 != "10") {
                        cout << "NO\n";
                        return;
                    }
                }else if (t1 == "01") {
                    if (s1 != "01") {
                        cout << "NO\n";
                        return;
                    }
                }
            }
            s1.clear();
            t1.clear();
        }
        r++;
        l = r;
    }   

    if (s1.size() == 1) {
        if (s1 != t1) { 
            cout << "NO\n";
        }else {
            cout << "YES\n";
        }
        return;
    }else if (s1.size() == 2) {
        if (t1 == "10") {
            if (s1 == "10") {
                cout << "YES\n";
            }else {
                cout << "NO\n";
            }
        }else if (t1 == "01") {
            if (s1 == "01") {
                cout << "YES\n";
            }else {
                cout << "NO\n";
            }
        }else {
            cout << "YES\n";
        }
        return;
    }

    cout << "YES\n";
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