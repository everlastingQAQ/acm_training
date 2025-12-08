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

    queue <ll> q;
    ll a, b;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            q.push(b);
        }else if (a == 2) {
            if (!q.empty()) {
                q.pop();
            }else {
                cout << "ERR_CANNOT_POP" << endl;
            }
        }else if (a == 3) {
            if (!q.empty()) {
                cout << q.front() << endl;
            }else {
                cout << "ERR_CANNOT_QUERY" << endl;
            }
        }else if (a == 4) {
            cout << q.size() << endl;
        }
    }
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