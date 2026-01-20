#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, m;
string s1 = "eat";
string s2 = "cook";

void solve ()
{
    cin >> n >> m;
    deque <pi> dq;

    for (int i = 1; i <= n; i++) {
        string s;
        ll t;
        cin >> s >> t;

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            if (y < i) {
                dq.pop_front();
            }else {
                break;  
            }
        }
        
        if (s == s2) {
            dq.push_back({t, i + m - 1});
        }else {
            ll sum = 0;
            for (auto [x, y] : dq) {
                sum += x;
            }
            if (sum < t) {
                cout << "wu wu wu" << '\n';
            }else {
                cout << "xie xie ni" << '\n';
                ll a = t;
                while (a > 0) {
                    auto [x, y] = dq.front();
                    dq.pop_front();
                    if (a - x >= 0) {
                        a -= x;
                    }else {
                        dq.push_front({x - a, y});
                        a = 0;
                    }
                }
            }
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