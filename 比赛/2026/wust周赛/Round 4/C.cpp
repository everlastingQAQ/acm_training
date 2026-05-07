#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    string s;
    cin >> s;
    if (s.size() == 1) {
        cout << "Yes\n";
        return;
    }else if (s.size() == 2) {
        if (s == "xo" || s == "ox" || s == "xx") {
            cout << "Yes\n";
            return;
        }else {
            cout << "No\n";
            return;
        }
    }
    if (s.size() == 3) {
        if (s == "xxo" || s == "xox" || s == "oxx") {
            cout << "Yes\n";
        }else {
            cout << "No\n";
        }
        return;
    }

    string t = s.substr(0, 3);
    // cout << t << '\n';
    if (t == "xox") s = "x" + s;
    else if (t == "oxx") s = "xx" + s;
    // cout << s << '\n';

    for (int i = 0; i < s.size(); i += 3) {
        if (i + 2 >= s.size()) {
            break;
        }
        string tt = s.substr(i, 3);
        if (tt != "xxo") {
            cout << "No\n";
            return;
        }
    }

    if (s.size() % 3 == 1) {
        char c1 = s.back();
        if (c1 != 'x') {
            cout << "No\n";
        }else {
            cout << "Yes\n";
        }
    }else if (s.size() % 3 == 2) {
        char c1 = s.back();
        char c2 = s[s.size() - 2];
        // cout << 99;
        if (c1 != 'x' || c2 != 'x') {
            cout << "No\n";
        }else {
            cout << "Yes\n";
        }
    }else {
        cout << "Yes\n";
    }
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