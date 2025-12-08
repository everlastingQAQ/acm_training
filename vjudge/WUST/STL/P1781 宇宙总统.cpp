#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

struct cmp{
    bool operator()(const pair<string, ll> &a, const pair<string, ll> &b) const {
        if (a.fi.length() != b.fi.length()) {
            return a.fi.length() < b.fi.length();
        }else {
            return a.fi < b.fi;
        }
    }
};

void solve ()
{
    cin >> n;
    priority_queue <pair<string, ll>, vector<pair<string, ll> >, cmp> pq;
    
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        pq.push({s, i});
    }

    cout << pq.top().second << endl;
    cout << pq.top().first << endl;

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

