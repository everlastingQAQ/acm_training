#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
    	cin >> v[i];
    }

    int N = sqrt(n);
    vector <vector <i64> > a(N + 1);
    for (int i = 1; i <= N; i++) {
    	a[i].assign(i, 0);
    }	
    
    for (int i = 1; i <= N; i++) {
    	for (int j = 1; j <= n; j++) {
    		a[i][j % i] += v[j];
    	}
    }

    for (int j = 1; j <= m; j++) {
    	char op;
    	cin >> op;
    	if (op == 'A') {
    		int x, y;
    		cin >> x >> y;
    		if (x <= N) {
    			cout << a[x][y] << '\n';
    		}else {
    			i64 ans = 0;
    			for (int i = y; i <= n; i += x) {
    				ans += v[i];
    			}
    			cout << ans << '\n';
    		}
    	}else {
    		int x, y;
    		cin >> x >> y;
    		for (int i = 1; i <= N; i++) {
    			a[i][x % i] -= v[x];
    			a[i][x % i] += y;
    		}
    		v[x] = y;
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