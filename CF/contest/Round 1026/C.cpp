#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
    	cin >> v[i];
    }
    vector <array <int, 2> > a(n + 1);
    for (int i = 1; i <= n; i++) {
    	cin >> a[i][0] >> a[i][1];
    }
    
    vector <array <int, 2> > b(n + 1);
    int mn = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
    	if (v[i] == 1) {
    		mn++;
    		mx++;
    	}else if (v[i] == -1) {
    		mx++;
    	}

    	if (mn > a[i][1] || mx < a[i][0]) {
    		cout << -1 << '\n';
    		return;
    	}

    	if (mn < a[i][0]) {
    		mn = a[i][0];
    	}

    	if (mx > a[i][1]) {
    		mx = a[i][1];
    	}

    	b[i][0] = mn;
    	b[i][1] = mx;
    }

    for (int i = n - 1; i >= 1; i--) {
    	if (v[i + 1] == 1) {
    		b[i][0] = max(b[i + 1][0] - 1, b[i][0]);
    		b[i][1] = min(b[i + 1][1] - 1, b[i][1]);
    	}else if (v[i + 1] == 0) {
    		b[i][0] = b[i + 1][0];
    		b[i][1] = b[i + 1][1];
    	}else {
    		b[i][0] = max(b[i + 1][0] - 1, b[i][0]);
    		b[i][1] = min(b[i + 1][1], b[i][1]);
    	}
    }

    vector <int> ans(n + 1);
    int cur = 0;
    for (int i = 1; i <= n; i++) {
    	if (v[i] == 1) {
    		cur++;
    		ans[i] = 1;
    	}else if (v[i] == 0) {
    		ans[i] = 0;
    	}else {
    		if (b[i][0] > cur + 1) {
    			cout << -1 << '\n';
    			return;
    		}else if (cur > b[i][1]) {
    			cout << -1 << '\n';
    			return;
    		}
    		if (cur + 1 == b[i][0]) {
    			cur++;
    			ans[i] = 1;
    		}else if (cur == b[i][1]) {
    			ans[i] = 0;
    		}
    	}
    }

    for (int i = 1; i <= n; i++) {
    	cout << ans[i] << " \n"[i == n];
    }


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