#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    char a, b;
    cin >> a >> b;
    if (a >= 'C' && b >= 'C') {
    	cout << (a > b ? a : b) << '\n';
    }else {
    	if (a < 'C' && b >= 'C') {
    		cout << a << '\n';
    	}else if (a >= 'C' && b < 'C') {
    		cout << b << '\n';
    	}else {
    		cout << (a > b ? a : b) << '\n';
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