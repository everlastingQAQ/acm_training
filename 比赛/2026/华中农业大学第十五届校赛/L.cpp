#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n, m;
	cin >> n >> m;
	vector <vector <char> > v(n + 1, vector <char> (m + 1));
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> v[i][j];
			if (v[i][j] != '.') cnt++;
		} 
	}
	
	vector <array <int, 2> > ans;
	ans.reserve(cnt + 1);
	
	vector <int> v1(m + 1, 1);//u
	vector <int> v2(m + 1, n);//d
	vector <int> v3(n + 1, 1);//l
	vector <int> v4(n + 1, m);//r	
	
	int pre = cnt;
	while (cnt > 0) {
		for (int j = 1; j <= m; j++) {
			int i = v1[j];
			while (i <= n && (v[i][j] == 'U' || v[i][j] == '.')) {
				if (v[i][j] == 'U') {
					ans.push_back({i, j});
					cnt--;
					v[i][j] = '.';
				}
				i++;
			}
			v1[j] = i;
		}
		
		for (int j = 1; j <= m; j++) {
			int i = v2[j];
			while (i >= 1 && (v[i][j] == 'D' || v[i][j] == '.')) {
				if (v[i][j] == 'D') {
					ans.push_back({i, j});
					cnt--;
					v[i][j] = '.';
				}
				i--;
			}
			v2[j] = i;
		}
		
		for (int i = 1; i <= n; i++) {
			int j = v3[i];
			while (j <= m && (v[i][j] == 'L' || v[i][j] == '.')) {
				if (v[i][j] == 'L') {
					ans.push_back({i, j});
					cnt--;
					v[i][j] = '.';
				}
				j++;
			}
			v3[i] = j;
		}
		
		for (int i = 1; i <= n; i++) {
			int j = v4[i];
			while (j >= 1 && (v[i][j] == 'R' || v[i][j] == '.')) {
				if (v[i][j] == 'R') {
					ans.push_back({i, j});
					cnt--;
					v[i][j] = '.';
				}
				j--;
			}
			v4[i] = j;
		}
		
		if (pre == cnt) {
			cout << -1 << '\n';
			return;
		}
		
		pre = cnt;
	}

	for (auto [x, y] : ans) {
		cout << x << ' ' << y << '\n';
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
