#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;
string s;

void solve ()
{
    cin >> n >> s;
    vector <char> stk;
    ll ans = 0;
    for (auto c : s) {
        if (c == '(') {
            stk.emplace_back(c);
        }else if (c == ')') {
            if (!stk.empty()) {
                stk.pop_back();
            }else {
                ans++;
            }
        }
    }
    ans += stk.size();
    cout << ans << '\n';
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