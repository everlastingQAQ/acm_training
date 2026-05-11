#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n & 1) {
        cout << "NO\n";
        return;
    }

    vector <char> stk;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        bool ok = false;
        if (!stk.empty() && stk.back() == c) {
            stk.pop_back();
        }else {
            stk.push_back(c);
        }
    }

    if (stk.empty()) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
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