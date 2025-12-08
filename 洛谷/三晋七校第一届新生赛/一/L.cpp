#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;

    stack <char> v;

    char c;
    ll cnt = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == '(') {
            v.push(c);
            cnt = 1;
        }else if (c == '#') {
            if (!v.empty() && v.top() == '(') {
                cnt++;
            }
        }else if (c == ')') {
            while (!v.empty()) {
                v.pop();
            }
            cnt++;
            ans = max(cnt, ans);
            cnt = 0;
        }
    }

    cout << ans << '\n';
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