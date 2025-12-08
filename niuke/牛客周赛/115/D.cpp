#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;

ll n;

bool cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    cin >> n;

    vector <pair<ll, ll> > memo(n);

    for (ll i = 0; i < n; i++) {
        cin >> memo[i].fi >> memo[i].se;
    }

    sort(memo.begin(), memo.end());

    priority_queue <ll, vector<ll>, greater<ll> > pq;

    ll mex = 0, idx = 0;

    while (1) {
        while (idx < n && memo[idx].fi <= mex) {
            pq.push(memo[idx].se);
            idx++;
        }
        while (pq.size() && pq.top() < mex) {
            pq.pop();
        }
        if (pq.empty()) {
            break;
        }
        pq.pop();
        mex++;
    }

    cout << mex << endl;
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