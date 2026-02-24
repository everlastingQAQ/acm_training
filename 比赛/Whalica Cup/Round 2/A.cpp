#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s;
    cin >> s;
    int a = stoi(s.substr(1, 2), 0, 16);
    int b = stoi(s.substr(3, 2), 0, 16);
    int c = stoi(s.substr(5, 2), 0, 16);

    int a1 = 255 - a;
    int b1 = 255 - b;
    int c1 = 255 - c;

    cout << '#';
    printf("%02x%02x%02x", a1, b1, c1);
    cout << '\n';
}   
    
int32_t main ()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
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