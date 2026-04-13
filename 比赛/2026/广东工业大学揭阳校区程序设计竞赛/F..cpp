#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve ()
{
	int n = 19;
  	vector <vector <char> > v (n + 1, vector <char> (n + 1));
  	vector <vector <int> > vis (n + 1, vector <int> (n + 1, 0));

  	for (int i = 1; i <= n; i ++) {
  		for (int j = 1; j <= n; j ++) {
  			cin >> v[i][j];
  		}
  	}  

  	double ans1 = 0, ans2 = 0;

  	for (int i = 1; i <= n; i ++) {
  		for (int j = 1; j <= n; j ++) {
  			

  			if (v[i][j] == 'B') ans1++;
  			else if (v[i][j] == 'W') ans2++;
  			else {
  				if (vis[i][j]) continue;
  				bool ok1 = false;
  				bool ok2 = false;
  				queue <array <int, 2> > q;
  				q.push({i, j});
  				vis[i][j] = true; 
  				int cnt = 0;
  				while (!q.empty()) {
  					auto [x, y] = q.front();
  					q.pop();
  					for (int i = 0; i < 4; i++) {
  						int xx = x + dx[i];
  						int yy = y + dy[i];
  						if (xx > n || xx < 1 || yy > n || yy < 1) continue;

  						if (v[xx][yy] == 'B') ok1 = true;
  						if (v[xx][yy] == 'W') ok2 = true;

  						if (vis[xx][yy]) continue;
  						cnt++;
  						vis[xx][yy] = 1;
  						q.push({xx, yy});
  					}
  				}
				if (ok1 && !ok2) ans1 += cnt;
  				if (!ok1 && ok2) ans2 += cnt;
  			}
  		}
  	}

  	cout << fixed << setprecision(2);
  	ans1 -= 7.5;

  	cout << ans1 << ' ' << ans2 << '\n';
  	if (ans1 > ans2) {
  		cout << "Black wins";
  	}else {
  		cout << "White wins";
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