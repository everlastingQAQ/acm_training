#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{	
    i64 n;
    cin >> n;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
    	cin >> v[i];
    }

    if (((2 * v[1] - v[2]) % (n + 1)) != 0) {
    	cout << "NO\n";
    	return;
    }

    i64 x = v[1] - n * (2 * v[1] - v[2]) / (n + 1);
    i64 y = (2 * v[1] - v[2]) / (n + 1);
    i64 d = x - y;
    if (x < 0 || y < 0) {
    	cout << "NO\n";
    	return;
    }

    for (int i = 3; i <= n; i++) {
    	if (v[i] != d * i + n * y + y) {
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