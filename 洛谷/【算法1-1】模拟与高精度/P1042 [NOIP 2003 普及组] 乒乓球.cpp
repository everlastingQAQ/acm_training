#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2505;

int main ()
{
    string s[MAXN];
    int i = 0;
    while (cin >> s[i]) {
        int cnt_w = 0;
        int cnt_l = 0;
        for (char c : s[i]) {
            if (c == 'W') {
                cnt_w++;
                if (cnt_w == 11) {
                    cout << cnt_w << ':' << cnt_l << endl;
                    cnt_w = 0;
                    cnt_l = 0;
                }
            }else if (c == 'L') {
                cnt_l++;
                if (cnt_l == 11) {
                    cout << cnt_w << ':' << cnt_l << endl;
                    cnt_w = 0;
                    cnt_l = 0;
                }
            }else if (c == 'E') {
                cout << cnt_w << ':' << cnt_l << endl;
            }
        }
        i++;
    }
}