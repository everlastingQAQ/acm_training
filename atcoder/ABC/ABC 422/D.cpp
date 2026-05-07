#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ll n, k;

void solve ()
{
    cin >> n >> k;
    vector <ll> ans{k};
    
    for (int i = 0; i < n; i++) {
        vector <ll> nxt;
        for (auto x : ans) {
            nxt.push_back(x / 2);
            nxt.push_back(x - x / 2);
        }
        ans = nxt;
    }
    
    cout << *max_element(ans.begin(), ans.end()) - *min_element(ans.begin(), ans.end()) << '\n';

    for (auto x : ans) {
        cout << x << ' ';
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