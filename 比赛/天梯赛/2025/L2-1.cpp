#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    string s;
    cin >> s;
    vector <char> stk;

    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            string ss;
            while (!stk.empty() && stk.back() != '(') {
                ss.push_back(stk.back());
                stk.pop_back();
            }
            reverse(ss.begin(), ss.end());
            cout << ss << '\n';
            stk.pop_back();
            continue;
        }else {
            stk.push_back(s[i]);
        }
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