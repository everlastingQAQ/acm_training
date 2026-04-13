#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

void solve ()
{
    ll n; cin >> n;
    string a, b; cin >> a >> b;
    cout << "Yes" << '\n'; 

    bool c[3];
    c[0] = false, c[1] = false, c[2] = false;
    for (char x : a) {
        if (x == 'a') {
            c[0] = true;
        }else if (x == 'b') {
            c[1] = true;
        }else if (x == 'c') {
            c[2] = true;
        }
    }

    for (char x : b) {
        if (x == 'a') {
            c[0] = true;
        }else if (x == 'b') {
            c[1] = true;
        }else if (x == 'c') {
            c[2] = true;
        }
    }
    
    if (a == b) {
        if (c[0] == false && c[1] == true && c[2] == true) {
            reverse(a.begin(), a.end());
            for (int i = 0; i < n; i++) {
                cout << 'a' << a;
            }
        }else if (c[0] == true && c[1] == false && c[2] == true) {
            reverse(a.begin(), a.end());
            for (int i = 0; i < n; i++) {
                cout << 'b' << a;
            }
        }else if (c[0] == true && c[1] == true && c[2] == false) {
            reverse(a.begin(), a.end());
            for (int i = 0; i < n; i++) {
                cout << 'c' << a;
            }
        }else if (c[0] + c[1] + c[2] == 1) {
            for (int i = 0; i < n; i++) {
                cout << "abc";
            }
        }
        return;
    }
    
    if (a[0] == a[1] && b[0] != b[1]) {
        if (a[0] != b[0] && a[1] != b[1]) {
            reverse(b.begin(), b.end());
            for (int i = 0; i < n; i++) {
                cout << b << a[0];
            }
        }else if (a[0] == b[0]) {
            if (c[0] == false) {
                for (int i = 0; i < n; i++) {
                    cout << 'a' << b[1] << b[0];
                }
            }else if (c[1] == false) {
                for (int i = 0; i < n; i++) {
                    cout << 'b' << b[1] << b[0];
                }
            }else if (c[2] == false) {
                for (int i = 0; i < n; i++) {
                    cout << 'c' << b[1] << b[0];
                }
            }
        }else if (a[0] == b[1]) {
            if (c[0] == false) {
                for (int i = 0; i < n; i++) {
                    cout << b[1] << b[0] << 'a';
                }
            }else if (c[1] == false) {
                for (int i = 0; i < n; i++) {
                    cout << b[1] << b[0] << 'b';
                }
            }else if (c[2] == false) {
                 for (int i = 0; i < n; i++) {
                    cout << b[1] << b[0] << 'c';
                }
            }
        }
        return;
    }else if (b[0] == b[1] && a[0] != a[1]) {
        if (a[0] != b[0] && a[1] != b[1]) {
            reverse(a.begin(), a.end());
            for (int i = 0; i < n; i++) {
                cout << a << b[0];
            }
        }else if (b[0] == a[0]) {
            if (c[0] == false) {
                for (int i = 0; i < n; i++) {
                    cout << 'a' << a[1] << a[0];
                }
            }else if (c[1] == false) {
                for (int i = 0; i < n; i++) {
                    cout << 'b' << a[1] << a[0];
                }
            }else if (c[2] == false) {
                for (int i = 0; i < n; i++) {
                    cout << 'c' << a[1] << a[0];
                }
            }
        }else if (b[0] == a[1]) {
            if (c[0] == false) {
                for (int i = 0; i < n; i++) {
                    cout << 'a' << a[1] << a[0];
                }
            }else if (c[1] == false) {
                for (int i = 0; i < n; i++) {
                    cout << 'b' << a[1] << a[0];
                }
            }else if (c[2] == false) {
                for (int i = 0; i < n; i++) {
                    cout << 'c' << a[1] << a[0];
                }
            }
        }
        return;
    }else if (a[0] == a[1] && b[0] == b[1]) {
        for (int i = 0; i < n; i++) {
            cout << "abc";
        }
        return;
    }

    if (a[0] == b[1] && a[1] == b[0]) {
        if (c[0] == false) {
            for (int i = 0; i < n; i++) {
                cout << 'b';
            }
            for (int i = 0; i < n; i++) {
                cout << 'a';
            }
            for (int i = 0; i < n; i++) {
                cout << 'c';
            }
        }else if (c[1] == false) {
            for (int i = 0; i < n; i++) {
                cout << 'c';
            }
            for (int i = 0; i < n; i++) {
                cout << 'b';
            }
            for (int i = 0; i < n; i++) {
                cout << 'a';
            }
        }else if (c[2] == false) {
            for (int i = 0; i < n; i++) {
                cout << 'b';
            }
            for (int i = 0; i < n; i++) {
                cout << 'c';
            }
            for (int i = 0; i < n; i++) {
                cout << 'a';
            }
        }
    }else if (a[0] == b[0] && a[1] != b[1]) {
        for (int i = 0; i < n; i++) {
            cout << a[1];
        }
        for (int i = 0; i < n; i++) {
            cout << b[1];
        }
        for (int i = 0; i < n; i++) {
            cout << a[0];
        }
    }else if (a[1] == b[0] && a[0] != b[1]) {
        reverse(b.begin(), b.end());
        string ss = b + a[0];
        for (int i = 0; i < n; i++) {
            cout << ss;
        }
    }else if (a[0] == b[1] && a[1] != b[0]) {
        reverse(a.begin(), a.end());
        string ss = b[0] + a;
        for (int i = 0; i < n; i++) {
            cout << ss;
        }
    }else if (a[1] == b[1] && a[0] != b[0]) {
        for (int i = 0; i < n; i++) {
            cout << a[1];
        }
        if (a[1] == 'a') {
            for (int i = 0; i < n; i++) {
                cout << 'b';
            }
            for (int i = 0; i < n; i++) {
                cout << 'c';
            }
        }else if (a[1] == 'b') {
            for (int i = 0; i < n; i++) {
                cout << 'a';
            }
            for (int i = 0; i < n; i++) {
                cout << 'c';
            }
        }else if (a[1] == 'c') {
            for (int i = 0; i < n; i++) {
                cout << 'a';
            }
            for (int i = 0; i < n; i++) {
                cout << 'b';
            }
        }
    }
}

int main ()
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
