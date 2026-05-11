#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;   
    int cnt = 0;
    for (auto c : s) {
        if (c == '1') cnt++;
    }
    if (cnt <= k || k > n / 2) {
        cout << "Alice\n";
    }else {
        cout << "Bob\n";
    }
} 
    
int main ()
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