#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	cin >> n;
  	string s, t;
  	cin >> s >> t;
  	vector <char> a, b;
  	int mxa = 0, mxb = 0;
  	int ca = 0, cb = 0;
  	for (int i = 0; i < n; i++) {
  		if (i > 0 && s[i] == ')' && s[i - 1] == '(') ca++;
  	}  

  	for (int i = 0; i < n; i++) {
  		if (t[i] == '(') {
  			b.push_back('(');
  		}else {
  			b.pop_back();
  		}
  		if (i > 0 && t[i] == ')' && t[i - 1] == '(') cb++;
  	}
  	// cout << ca << ' ' << cb << '\n';
  	cout << ((mxa == mxb and ca == cb) ? "YES\n" : "NO\n");
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