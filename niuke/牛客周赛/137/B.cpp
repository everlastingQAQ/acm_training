#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	cin >> n;
  	string s;
  	cin >> s;
  	deque <char> dq;
  	int op = 0;
  	for (auto c : s) {
  		// cout << c << '\n';
  		if (c == '!') {
  			if (op == 0) op = 1;
  			else op = 0;
  			continue;
  		}else if (c == '-') {
  			if (dq.empty()) continue;
  			if (op == 0) {
  				dq.pop_back();
  			}else {
  				dq.pop_front();
  			}
  			continue;
  		}
  		// cout << c << '\n';
  		if (op == 0) {
  			dq.push_back(c);
  		}else {
  			dq.push_front(c);
  		}
  	}  

  	// cout << dq.back() << '\n';

  	if (dq.empty()) {
  		cout << "Empty\n";
  	}else {
  		while (!dq.empty()) {
  			char c = dq.front();
  			cout << c;
  			dq.pop_front();
  		}
  		cout << '\n';
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