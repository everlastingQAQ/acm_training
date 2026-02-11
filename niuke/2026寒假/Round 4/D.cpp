#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int x, a, s;
    cin >> x >> a >> s;
    if (a > x && s > x) {
        cout << "No\n";
        return;
    }

    int sum = -1;
    int temp = 1;
    while (sum < x) {
        sum = temp * (a + s);
        temp++;
    }

    
}   
    
int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;   
    while (_--) {
        solve();
    }
    return 0;
} 

/*
  /\_/\
 (= ._.)
 / >  \>
*/