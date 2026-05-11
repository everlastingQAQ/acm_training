#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    string s;
    cin >> s;
    vector <string> v(10);
    for (int i = 0; i < 10; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < 8; i++) {
        string t = s.substr(i * 10, 10);
        for (int j = 0; j < 10; j++) {
            if (t == v[j]) {
                cout << j;
                break;
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