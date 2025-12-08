#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000000;
string s1, s2;
ll len_1, len_2, len_3;
int a[MAXN + 10] = {}, b[MAXN + 10] = {}, ans[MAXN] = {}; 

//未处理输入负数的情况且输入需合法

void store (string s, ll &len, int a[MAXN])
{
    len = s.length();
    for (int i = 0; i < len; i++) {
        a[len - i] = s[i] - '0';
    }
}

bool is_negative (string &s1, string &s2) 
{
    if (s1.length() < s2.length()) return true;
    if (s1.length() > s2.length()) return false;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] < s2[i]) return true;
        if (s1[i] > s2[i]) return false;
    }
    return false;
}

int main ()
{
    cin >> s1 >> s2;

    if (s1 == s2) {
        cout << 0;
        return 0;
    }

    bool negative = false;
    if (is_negative(s1, s2)) {
        swap(s1, s2);
        negative = true;
    }

    store(s1, len_1, a);
    store(s2, len_2, b);

    len_3 = max(len_1, len_2);

    for (int i = 1; i <= len_3; i++) {
        if (a[i] < b[i]) {
            a[i] += 10;
            a[i+1]--;
        }
        ans[i] = a[i] - b[i];
    }

    while (len_3 > 1 && ans[len_3] == 0) {
        len_3--;
    }

    if (negative) cout << '-';

    for (int i = len_3; i > 0; i--) {
        cout << ans[i];
    }

    return 0;
}
