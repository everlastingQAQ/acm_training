#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    if (n % 9 != 0) {
        cout << "0\n";
        return;
    }

    int cnt = 0;
    for (int i = n; i <= n + 100; i++) {
        string t = to_string(i);
        int sum = 0;
        for (char c : t) {
            sum += c - '0';
        }
        if (i - sum == n) cnt++;
    }
    cout << cnt << '\n';
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