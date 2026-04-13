#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector <string> v;
    do {
        v.push_back(s);
    }while (next_permutation(s.begin(), s.end()));
    cout << v.size() << '\n';
    for (auto ss : v) {
        cout << ss << '\n';
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