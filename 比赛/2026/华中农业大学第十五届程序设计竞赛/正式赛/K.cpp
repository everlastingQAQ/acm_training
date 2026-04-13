#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const ll MAXN = 1e8;
const ld eps = 1e-12;
const ll mod = 998244353;

ll n, k;
string s;

void solve ()
{
	cin >> n >> k;
    vector <ll> v(n + 1);   
    
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector <ll> s(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1];
        if (v[i] > k) {
            s[i]++;
        }else if (v[i] < k) {
            s[i]--;
        }
    }

    vector <vector<ll> > pos(2 * n + 2);
    pos[n].push_back(0);
    ll ans = 0; 
    ll exist = -1;

    for (int i = 1; i <= n; i++) {
        pos[s[i] + n].push_back(i);
        if (v[i] == k) {
            exist = i;
        }
        if (exist != -1) {
            ans += lower_bound(pos[s[i] + n].begin(), pos[s[i] + n].end(), exist) - pos[s[i] + n].begin();
        }
    }
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
