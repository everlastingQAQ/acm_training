#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string s;
    cin >> s;
    string res;
    for (int i = 0; i < s.length(); i++) {
        if (i == s.length() - 1) {
            res += s[0] + s[i];
        }else {
            res += s[i] + s[i + 1];
        }
    }
    cout << res;
    return 0;
}