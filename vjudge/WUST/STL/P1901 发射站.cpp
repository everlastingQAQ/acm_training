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

    vector <ll> a(n);
    vector <ll> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    stack <ll> stk;
    vector <ll> ans(n);

    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[stk.top()] < a[i]) {
            ans[i] += b[stk.top()];
            stk.pop();
        }
        if (!stk.empty()) {
            ans[stk.top()] += b[i];
        }
        stk.push(i);
    }

    auto it = max_element(ans.begin(), ans.end());

    cout << *it << '\n';

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