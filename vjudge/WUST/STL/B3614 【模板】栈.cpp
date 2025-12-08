#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;

    stack <ll> stk;
    string s;
    ll a;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "push") {
            cin >> a;
            stk.push(a);
        }else if (s == "query") {
            if (!stk.empty()) {
                cout << stk.top() << '\n';
            }else {
                cout << "Anguei!" << '\n';
            }
        }else if (s == "size") {
            cout << stk.size() << '\n';
        }else if (s == "pop") {
            if (!stk.empty()) {
                stk.pop();
            }else {
                cout << "Empty" << '\n';
            }
        }
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