#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<string, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll n, m; cin >> n >> m;
    string aa, bb; cin >> aa >> bb;
    queue <int> a, b;
    for (char c : aa) a.emplace(c - '0');
    for (char c : bb) b.emplace(c - '0');

    while (a.size() && b.size()) {
        if (a.front() == b.front()) {
            a.pop();
            b.pop();
        }else {
            int t = a.front();
            a.pop();
            a.front() ^= t;
        }
    }

    int t = 0;
    while (a.size()) {
        t ^= a.front();
        a.pop();
    }

    if (t == 0 && b.empty()) {
        cout << "YES" << '\n';
    }else {
        cout << "NO" << '\n';
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