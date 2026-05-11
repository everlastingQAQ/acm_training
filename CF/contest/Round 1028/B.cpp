#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 998244353;

i64 qpow (i64 a, i64 b)//a的b次方
{
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve ()
{
  	int n;
  	cin >> n;
  	vector <i64> a(n + 1), b(n + 1);
  	vector <array <i64, 2> > pa(n + 1), pb(n + 1);
  	for (int i = 1; i <= n; i++) {
  		cin >> a[i];
  		if (i == 1 || a[i] > pa[i - 1][0]) {
  			pa[i][0] = a[i];
  			pa[i][1] = i;
  		}else {
  			pa[i][0] = pa[i - 1][0];
  			pa[i][1] = pa[i - 1][1];
  		}
  	}  

  	for (int i = 1; i <= n; i++) {
  		cin >> b[i];
  		if (i == 1 || b[i] > pb[i - 1][0]) {
  			pb[i][0] = b[i];
  			pb[i][1] = i;
  		}else {
  			pb[i][0] = pb[i - 1][0];
  			pb[i][1] = pb[i - 1][1];
  		}
  	}

  	// for (auto [x, y] : pa) {
  	// 	cout << x << ' ' << y << '\n';
  	// }

  	for (int i = 1; i <= n; i++) {
  		if (pa[i][0] > pb[i][0]) {
  			i64 s1 = qpow(2, pa[i][0]);
  			i64 s2 = qpow(2, b[i - pa[i][1] + 1]);
  			// cout << s1 << ' ' << s2 << '\n';
  			i64 cur = (s1 + s2) % mod;
  			cout << cur << ' ';
  		}else if (pa[i][0] < pb[i][0]) {
  			i64 s1 = qpow(2, pb[i][0]);
  			i64 s2 = qpow(2, a[i - pb[i][1] + 1]);
  			// cout << s1 << ' ' << s2 << '\n';
  			i64 cur = (s1 + s2) % mod;
  			cout << cur << ' ';
  		}else {
  			i64 s1 = qpow(2, pa[i][0]);
            i64 s2 = qpow(2, max(a[i - pb[i][1] + 1], b[i - pa[i][1] + 1]));
            i64 cur = (s1 + s2) % mod;
            cout << cur << ' ';
  		}
  	}
  	cout << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 