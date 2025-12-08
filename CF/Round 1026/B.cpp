#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

string s;

void solve ()
{
    cin >> s;
    vector <char> stk;
    stk.push_back(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (stk.empty()) {
            cout << "Yes" << '\n';
            return;
        }
        if (s[i] == '(') {
            stk.emplace_back('(');
        }else if (s[i] == ')') {
            stk.pop_back();
        }
    }

    cout << "No" << '\n';
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