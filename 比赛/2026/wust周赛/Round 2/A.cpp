#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    string s;
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        if (s == "and" || s == "not" || s == "that" || s == "the" || s == "you") {
            ok = true;
        }
    }
    if (ok) {
        cout << "Yes\n";
    }else {
        cout << "No\n";
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
