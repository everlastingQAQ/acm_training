#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	i64 n;
  	cin >> n;
  	i64 t = n * (n + 1) / 2;
  	if (t & 1) {
  		cout << "NO\n";
  		return;
  	}
  	cout << "YES\n";
  	vector <int> vis(n + 1);
  	vector <int> a;
  	t /= 2;
  	i64 sum = 0;
  	map <int, int> mp;
  	for (int i = n; i >= 1; i--) {
  		sum += i;
  		a.push_back(i);
  		mp[i] = true;
  		if (sum == t) break;
  		if (t - sum < i) {
  			a.push_back(t - sum);
  			mp[t - sum] = true;
  			break;
  		}
  	}
  	cout << a.size() << '\n';
  	for (auto x : a) {
  		cout << x << " \n"[x == a.back()];
  	}
  	cout << n - a.size() << '\n';
  	for (int i = 1; i <= n; i++) {
  		if (!mp[i]) {
  			cout << i << " \n"[i == n];
  		}
  	}
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 