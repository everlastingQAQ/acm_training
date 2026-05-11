#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	cin >> n;
  	int mx = 0;
  	vector <int> v(n + 1);
  	for (int i = 1; i <= n; i++) {
  		cin >> v[i];
  		mx = max(v[i], mx);
  	}  
  	int d = v[1];
  	for (int i = 2; i <= n; i++) {
  		d = gcd(d, v[i]);
  	}
  	int cnt = 0;
  	for (int i = 1; i <= n; i++) {
  		if (v[i] == d) {
  			cnt++;
  		}	
  	}

  	if (cnt) {
  		cout << n - cnt << '\n';
  		return;
  	}

  	queue <int> q;
  	vector <int> dis(mx + 1, 1e9);
  	for (int i = 1; i <= n; i++) {
  		if (dis[v[i]] == 1e9) {
  			dis[v[i]] = 0;
  			q.push(v[i]);
  		}
  	}

  	while (!q.empty()) {
  		int x = q.front();
  		q.pop();
  		for (int i = 1; i <= n; i++) {
  			int y = gcd(x, v[i]);
  			if (dis[y] == 1e9) {
  				dis[y] = dis[x] + 1;
  				q.push(y);
  			}
  		}
  	}

  	cout << dis[d] + (n - 1) << '\n';
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