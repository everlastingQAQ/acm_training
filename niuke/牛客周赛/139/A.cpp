#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    string s;
    cin >> s;
    for (auto c : s) {
        if (c != 'r' && c != 'e' && c != 'd') {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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
