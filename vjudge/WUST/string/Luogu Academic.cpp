#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string s;
    cin >> s;
    string t = "luogu";
    long long cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        auto it = t.begin();
        if (s[i] == *it) {
            bool test = true;
            int j = i;
            while (it != t.end()) {
                if (s[j++] == *(it++) && j <= s.length()) {
                    continue;
                }else {
                    test = false;
                    break;
                }
            }
            if (test) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}