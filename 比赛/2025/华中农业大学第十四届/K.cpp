#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] > s[i - 1]) {
            swap(s[i], s[i - 1]);
            break;
        }
    }
    cout << s << '\n';
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