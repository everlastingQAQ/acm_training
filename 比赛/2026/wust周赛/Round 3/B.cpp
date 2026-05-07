#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	string s;
    cin >> s;

    if (s.size() == 1) {
        cout << "NO\n";
        return;
    }
    if (s[0] != '1') {
        cout << "NO\n";
        return;
    }
    if (s[s.size() - 1] == '9') {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == '0') {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}