#include <bits/stdc++.h>
using namespace std;
int n;
string s;

int main ()
{
    cin >> n >> s;
    string res;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] + n > 'z') {
            res += (s[i] - 'a' + n) % 26 + 'a';
        }else {
            res += s[i] + n;
        }
    }
    cout << res;
    return 0;
}