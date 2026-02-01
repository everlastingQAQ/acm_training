#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s; cin >> s;
    int n = s.size();
    int a = s[0] - '0';
    int b = s[1] - '0';
    if (n > 2 && s[2] >= '5') b++;

    if (b == 10) {
        b = 0, a++;
    }

    if (a == 10) {
        cout << "1.0*10^" << n;
    }else {
        cout << a << '.' << b << "*10^" << n - 1;
    }
    
}   
    
int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 