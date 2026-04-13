#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	cin >> n;
  	vector <pair <string, double> > ans;
  	for (int i = 1; i <= n; i++) {
  		string s;
  		double t;
  		cin >> s >> t;
  		if (t <= 3.0) {
  			ans.push_back({s, t});
  		}
  	}  
  	sort(ans.begin(), ans.end(), [] (auto a, auto b) {
		if (a.second != b.second) return a.second < b.second;
		else {
			return a.first < b.first;
		}	
  	});

  	cout << ans.size() << '\n';
  	for (auto x : ans) {
  		cout << x << '\n';
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