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
  	int ans = 1;
  	int cnt = 1;
  	int cntt = 0;
  	map <int, int> mp, mpp;
  	mp[v[1]] = true;

  	for (int i = 2; i <= n; i++) {
  		if (mp[v[i]]) {
  			cnt--;
  			mp[v[i]] = false;
  			mpp[v[i]] = true;
  			cntt++;
  		}else {
  			if (!mpp[v[i]]) cntt++;
  			mpp[v[i]] = true;
  		}

  		if (cnt == 0) {
  			cnt = cntt;
  			cntt = 0;
  			ans++;
  			mp = mpp;
  			mpp.clear();
  		}
  	}

  	cout << ans << '\n';
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