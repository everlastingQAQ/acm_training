#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;

void solve ()
{
    stack <ll> stk;
    string s;
    cin >> s;
    ll a = 0, b = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            b = s[i] - '0';
            a = a * 10 + b;
        }else if (s[i] == '.') {
            stk.push(a);
            a = 0;
        }else if (s[i] == '+') {
            ll c = stk.top(); stk.pop();
            ll d = stk.top(); stk.pop();
            stk.push(d + c);
        }else if (s[i] == '-') {
            ll c = stk.top(); stk.pop();
            ll d = stk.top(); stk.pop();
            stk.push(d - c);
        }else if (s[i] == '*') {
            ll c = stk.top(); stk.pop();
            ll d = stk.top(); stk.pop();
            stk.push(d * c);
        }else if (s[i] == '/') {
            ll c = stk.top(); stk.pop();
            ll d = stk.top(); stk.pop();
            stk.push(d / c);
        }
    }

    cout << stk.top() << '\n';

    return;
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