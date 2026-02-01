#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s; cin >> s;
    int n = s.size();
    int a = 0, b = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) a++;
        else b++;
    } 
    cout << a * b + 1 << '\n';
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