#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 y, x;
    cin >> y >> x;
    if (y >= x) {
    	if (y & 1) {
    		cout << (y - 1) * (y - 1) + x << '\n';
    	}else {
    		cout << y * y - x + 1 << '\n';
    	}
    }else {
    	if (x & 1) {
    		cout << x * x - y + 1 << '\n';
    	}else {
    		cout << (x - 1) * (x - 1) + y << '\n';
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