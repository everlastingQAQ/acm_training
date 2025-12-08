#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
string s;

void solve ()
{
    cin >> s;

    stack <char> stk;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stk.push(s[i]);
        }else if (s[i] == ')') {
            if (stk.empty()) {
                cout << "No" << '\n';
                return;
            }
            if (stk.top() != '(') {
                cout << "No" << '\n';
                return;
            }else {
                stk.pop();
            }
        }else if (s[i] == ']') {
            if (stk.empty()) {
                cout << "No" << '\n';
                return;
            }
            if (stk.top() != '[') {
                cout << "No" << '\n';
                return;
            }else {
                stk.pop();
            }
        }else if (s[i] == '}') {
            if (stk.empty()) {
                cout << "No" << '\n';
                return;
            }
            if (stk.top() != '{') {
                cout << "No" << '\n';
                return;
            }else {
                stk.pop();
            }
        }
    }
    if (stk.empty()) {
        cout << "Yes" << '\n';
    }else {
        cout << "No" << '\n';
    }
    
}   

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}