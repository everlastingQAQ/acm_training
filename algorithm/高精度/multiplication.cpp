#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100000000;
string s1, s2;
ll len_1, len_2, len_3;
int a[MAXN] = {}, b[MAXN] = {}, ans[MAXN] = {}; 

//未处理输入负数的情况且输入需合法

void store (string s, ll &len, int a[MAXN])
{
    len = s.length();
    for (int i = 0; i < len; i++) {
        a[len - i] = s[i] - '0';
    }
}

int main ()
{
    cin >> s1 >> s2;

    store(s1, len_1, a);
    store(s2, len_2, b);

    len_3 = len_1 + len_2;

    for (int i = 1; i <= len_1; i++) {
        for (int j = 1; j <= len_2; j++) {
            ans[i + j - 1] += a[i] * b[j]; // 个位和个位的积在个位上， 个位和十位的积在十位上......
            ans[i + j] += ans[i + j - 1] / 10; // 处理进位
            ans[i + j - 1] %= 10;
        }
    }

    if (ans[len_3] == 0) len_3--;

    for (int i = len_3; i > 0; i--) {
        cout << ans[i];
    }

    return 0;
}