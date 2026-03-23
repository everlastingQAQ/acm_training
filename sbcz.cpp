#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    dp[1] = 1; pre[1] = 1;
    dp[2] = 2; pre[2] = 3;
    dp[3] = 3; pre[3] = 6;// 3 + 0, 2 + 1, 1 + 1 + 1, 
    dp[4] = 5; pre[4] = 11;// 4 + 0, 3 + 1, 2 + 2, 2 + 1 + 1, 1 + 1 + 1 + 1,
    dp[5] = 7; pre[5] = 18;// 5 + 0, 4 + 1, 3 + 2, 3 + 1 + 1, 2 + 2 + 1, 2 + 1 + 1 + 1, 1 + 1 + 1 + 1 + 1,
    dp[6] = 11;pre[6] = 29;// 6 + 0, 5 + 1, 4 + 2, 4 + 1 + 1, 3 + 3, 3 + 2 + 1, 3 + 1 + 1 + 1, 2 + 2 + 2, 2 + 2 + 1 + 1, 2 + 1 + 1 + 1 + 1, 1 + 1 + 1 + 1 + 1 + 1,
    
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