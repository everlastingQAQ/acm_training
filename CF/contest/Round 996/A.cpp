#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n, a, b;
	cin >> n >> a >> b;
	cout << (abs(a - b) & 1 ? "NO\n" : "YES\n");    
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