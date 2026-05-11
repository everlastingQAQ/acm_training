#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int op;
    if (n & 1) {
        op = 0;
    }else {
        op = 1;
    }

    int idx = 0;
    while (idx < n) {
        if (op == 0) {
            if (s[idx] == 'b') {
                // cout << idx << ' ' << '\n';
                cout << "NO\n";
                return;
            }
            s[idx] = 'a';
            op = 1;
        }else if (op == 1) {
            if (s[idx] == 'a') {
                op = 2;
            }else if (s[idx] == 'b') {
                op = 0;
            }else {
                if (idx < n - 1) {
                    if (s[idx + 1] == 'a') {
                        op = 0;
                        s[idx] = 'b';
                    }else if (s[idx + 1] == 'b') {
                        op = 2;
                        s[idx] = 'a';
                    }else {
                        if (idx > 1) {
                            if (s[idx - 1] == 'a') {
                                op = 2;
                                s[idx] = 'a';
                            }else if (s[idx - 1] == 'b') {
                                op = 0;
                                s[idx] = 'b';
                            }
                        }else {
                            s[idx] = 'a';
                            op = 2;
                        }
                    }
                }
            }
        }else if (op == 2) {
            if (s[idx] == 'a') {
                // cout << idx << ' ' << '\n';
                cout << "NO\n";
                return;
            }
            op = 1;
            s[idx] = 'b';
        }
        idx++;
    }
    cout << "YES\n";
}   
    
int main ()
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