#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1002;

int main ()
{
    string s[MAXN];
    string ans[MAXN];
    int cnt = 0;
    while (cin >> s[cnt]) {
        cnt++;
    }
    
    for (int i = 0; i < cnt; i++) {
        
        for (int k = 1; k < s[i].length(); k++) {
            string t = s[i].substr(0, k);
            bool is_repetition = false;
            for (int j = 0; j < cnt; j++) {
                if (j == i) {
                    continue;
                }
                if (k < s[j].length() && s[j].substr(0, k) == t) {
                    is_repetition = true;
                    break;
                }else if (k >= s[j].length()) {
                    continue;
                }
            }
            if (is_repetition == false) {
                ans[i] = s[i].substr(0, k);
                break;
            }
            if (k == s[i].length() - 1) {
                ans[i] = s[i];
                break;
            }
        }
        
    }

    for (int i = 0; i < cnt; i++) {
        cout << s[i] << ' ' << ans[i] << endl;
    }

    return 0;

}