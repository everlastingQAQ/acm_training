#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1e6 + 1;
vector <int> p(N);

void init ()
{
	iota(p.begin(), p.end(), 0);
	for (int i = 2; i <= N; i++) {
		if (p[i] == i) {
			for (int j = i; j < N; j += i) {
				p[j] = i;
			}
		}
	}
}

void solve ()
{
  	int n;
  	cin >> n;
  	vector <int> v(n + 1);  
  	for (int i = 1; i <= n; i++) {
  		cin >> v[i];
  	}

  	auto get = [&] (int x) -> vector <int> {
  		vector <int> res;
  		while (x > 1) {
  			int t = p[x];
  			res.push_back(t);
  			while (x % t == 0) {
  				x /= t;
  			}
  		}
  		return res;
  	};

  	bool ok = true;
  	vector <int> vis(N + 1);
  	for (int i = 1; i <= n; i++) {
  		for (auto &t : get(v[i])) {
  			if (vis[t] > v[i]) {
  				ok = false;
  				break;
  			}else {
  				vis[t] = v[i];	
  			}
  		}
  	}

  	cout << (ok ? "SI\n" : "NO\n");
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
} 