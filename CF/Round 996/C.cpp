#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	
	vector <vector <i64> > v(n + 1, vector <i64> (m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> v[i][j];
		}
	}    

	int cx = 1, cy = 1;
	vector <int> x(n + 1, 0), y(m + 1, 0);
	vector <vector <int> > vis(n + 1, vector <int> (m + 1, 0));
	for (int i = 0; i < n + m - 2; i++) {
		x[cx]++;
		y[cy]++;
		vis[cx][cy]++;
		if (s[i] == 'D') {
			cx++;
		}else if (s[i] == 'R') {
			cy++;
		}
	}
	x[cx]++;
	y[cy]++;
	vis[cx][cy]++;

	int cnt = n + m - 1;
	while (cnt > 0) {
		for (int i = 1; i <= n; i++) {
			if (x[i] == 1) {
				int px, py;
				i64 sum = 0;
				for (int j = 1; j <= m; j++) {
					if (vis[i][j]) {
						px = i;
						py = j;
					}else {
						sum += v[i][j];
					}
				}
				v[px][py] = 0 - sum;
				vis[px][py] = 0;
				x[px]--;
				y[py]--;
				cnt--;
			}
		}

		for (int j = 1; j <= m; j++) {
			if (y[j] == 1) {
				int px, py;
				i64 sum = 0;
				for (int i = 1; i <= n; i++) {
					if (vis[i][j]) {
						px = i;
						py = j;
					}else {
						sum += v[i][j];
					}
				}
				v[px][py] = 0 - sum;
				vis[px][py] = 0;
				x[px]--;
				y[py]--;
				cnt--;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << v[i][j] << " \n"[j == m];
		}
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