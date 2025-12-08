#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 200010;

void solve ()
{
    string s;
    cin >> s;

    int l = 0, r = s.size() - 1;

    bool is_Palindromes = true;
    while (l <= r && is_Palindromes) {
        if (s[l] != s[r]) {
            is_Palindromes = false;
        }
        l++;
        r--;
    }
    if (is_Palindromes) {
        cout << "yes" << endl;
    }else {
        cout << "no" << endl;
    }
    return;
}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _ = 1;
	cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}