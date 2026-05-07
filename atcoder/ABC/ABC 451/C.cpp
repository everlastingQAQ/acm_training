#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	int n;
  	cin >> n;
  	priority_queue <int, vector <int>, greater<int> > pq;
  	for (int i = 1; i <= n; i++) {
  		int op, a;
  		cin >> op >> a;
  		if (op == 1) {
  			pq.push(a);
  		}else {
  			while (!pq.empty()) {
  				int x = pq.top();
  				if (x > a) {
  					break;
  				}
  				pq.pop();
  			}
  		}
  		cout << pq.size() << '\n';
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