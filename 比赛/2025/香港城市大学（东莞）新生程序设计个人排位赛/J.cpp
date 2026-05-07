#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 0) {
        vector <char> stk;
        for (int i = 0; i < n; i++) {
            stk.push_back(s[i]);
            while (stk.size() >= 2) {
                char c1 = stk.back();
                stk.pop_back();
                if (stk.back() == c1) {
                    stk.pop_back();
                }else {
                    stk.push_back(c1);
                    break;
                }
            }
        }
        cout << stk.size() << '\n';
    }else {
        cout << (n & 1 ? 1 : 0) << '\n';
    }
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