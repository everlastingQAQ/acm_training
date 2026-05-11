#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	cin >> n;
  	vector <i64> a(n + 1), b(n + 1);
  	i64 suma = 0;
  	for (int i = 1; i <= n; i++) {
  		cin >> a[i];
  		suma += a[i];
  	}  
  	for (int i = 1; i <= n; i++) {
  		cin >> b[i];
  	}
  	int cnt = 0;
  	i64 sum = 0;
  	for (int i = 1; i <= n; i++) {
  		cnt += (b[i] > a[i] ? 1 : 0);
  		sum += max(b[i] - a[i], 0LL);
  	}

  	if (cnt > 1) {
  		cout << "NO\n";
  		return;
  	}else if (cnt == 0) {
  		cout << "YES\n";
  		return;
  	}

  	for (int i = 1; i <= n; i++) {
  		if (b[i] > a[i]) continue;
  		if (a[i] - b[i] < sum) {
  			cout << "NO\n";
  			return;
  		}
  	}

  	cout << "YES\n";
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