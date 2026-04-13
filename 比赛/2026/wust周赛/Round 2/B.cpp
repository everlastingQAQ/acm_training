#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int a, b;
    cin >> a >> b;
    int cnt = 0;
    while ((a >= 1 && b >= 1) && a > 0 && b > 0) {
        if (a == 1 && b == 1) break;
        if (a > b) {
            a -= 2;
            b += 1;
        }else {
            b -= 2;
            a += 1;
        }
        cnt++;
    }
    cout << cnt << '\n';
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
