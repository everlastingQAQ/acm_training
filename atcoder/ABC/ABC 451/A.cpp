#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    string s;
    cin >> s;
    if (s.size() % 5 == 0) {
    	cout << "Yes\n";
    }else {
    	cout << "No\n";
    }
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