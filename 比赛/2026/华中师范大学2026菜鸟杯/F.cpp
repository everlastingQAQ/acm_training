#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int m = 450;
const int mx = 2e5 + 5;

class BIT {
    public:
        int n;
        vector <i64> bit;

        BIT (int n = 0) {init(n);}

        void init (int m) {
            n = m;
            bit.assign(n + 1, 0);
        }

        static i64 lowbit (i64 x) { return x & -x; }

        i64 sum (int idx) const {
            i64 res = 0;
            for (; idx > 0; idx -= lowbit(idx)) res += bit[idx];
            return res; 
        }

        void point_add (int idx, i64 diff) {
            for (; idx <= n; idx += lowbit(idx)) bit[idx] += diff;
        }

        i64 point_query (int idx) const {
            return sum(idx) - sum(idx - 1);
        }

};

void solve ()
{
    int n, q;
    cin >> n >> q;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
    	cin >> v[i];
    }

    BIT bit(mx + 2);
    for (int i = 1; i <= n; i++) {
    	bit.point_add(v[i] + 1, 1);
    }

    vector <vector <int> > a(m + 1);
    for (int i = 1; i <= m; i++) {
    	a[i].assign(i, 0);
    }
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		a[j][v[i] % j]++;
    	}
    }

    while (q--) {
    	int op;
    	cin >> op;
    	if (op == 1) {
    		int x, b;
    		cin >> x >> b;
    		if (v[x] == b) continue;
    		bit.point_add(v[x] + 1, -1);
    		bit.point_add(b + 1, 1);
    		for (int i = 1; i <= m; i++) {
    			a[i][v[x] % i]--;
    			a[i][b % i]++;
    		}
    		v[x] = b;
    	}else {
    		int x;
    		cin >> x;
    		if (x <= m) {
    			int sum = 0;
    			int ans = 0;
    			for (int i = 0; i < x; i++) {
    				sum += a[x][i];
    				if (sum >= (n + 1) / 2) {
    					ans = i;
    					break;
    				}
    			}
    			cout << ans << '\n';
    		}else {
    			int l = 0, r = x - 1;

    			auto check = [&] (int md) -> bool {
    				int res = 0;
    				for (int i = 0; i <= mx; i += x) {
    					res += bit.sum(min(i + md, mx) + 1) - bit.sum(i);
    				}
    				return res >= (n + 1) / 2;
    			};

    			while (l <= r) {
    				int mid = l + (r - l) / 2;
    				if (check(mid)) {
    					r = mid - 1;
    				}else {
    					l = mid + 1;
    				}
    			}
    			cout << l << '\n';
    		}
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