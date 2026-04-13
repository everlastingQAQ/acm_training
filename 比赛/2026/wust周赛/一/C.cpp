#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 1e9 + 7;

ll n;

void solve ()
{
    cin >> n;
    unordered_map <ll, ll> mp;
    queue<ll> q;
    while (n--) {
        ll a;
        cin >> a;
        if (a == 1) {
            ll b, c;
            cin >> b >> c;
            mp[b] += c;
            q.push(b);
        }else if (a == 2) {
            ll b, c;
            cin >> b >> c;
            mp[b] = max(0LL, mp[b] - c);
        }else if (a == 3) {
            while (!q.empty()) {
                if (mp[q.front()] > 1) {
                    mp[q.front()] = 1LL;
                }
                q.pop();
            }
        }else if (a == 4) {
            ll b;
            cin >> b;
            cout << max(0LL, mp[b]) << '\n';
        }
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