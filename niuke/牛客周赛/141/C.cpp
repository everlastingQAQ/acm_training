#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    string s;
    cin >> s;

    if (s.size() == 1) {
        cout << "YES\n";
        return;
    }else if (s.size() == 2) {
        if (s[0] != s[1]) {
            cout << "NO\n";
        }else {
            cout << "YES\n";
        }
        return;
    }

    int l = 0, r = s.size() - 1;
    while (l <= r) {
        if (s[l] == s[r]) {
            l++;
            r--;
            continue;
        }else if (s[l] == 'm' && s[r] == 'n') {
            if (s[r - 1] != 'n') {
                cout << "NO\n";
                return;
            }
            r -= 2;
            l++;
        }else if (s[l] == 'n' && s[r] == 'm') {
            if (s[l + 1] != 'n') {
                cout << "NO\n";
                return;
            }
            l += 2;
            r--;
        }
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