#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    string s;
    cin >> s;
    vector <char> ans; 
    for (int i = 0; i < s.size(); i++) {
        if (i < s.size() - 1 && s[i] == '/' && s[i + 1] == '/') {
            break;
        }else { 
            ans.push_back(s[i]);
        }
    }
    if (ans.empty()) {
        cout << "null";
    }else {
        for (auto c : ans) {
            cout << c;
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