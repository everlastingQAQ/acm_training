#include <bits/stdc++.h>
using namespace std;

string s[26] = {"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen",
    "fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","a","both","another","first","second","third"};
int a[26] = {1,4,9,16,25,36,49,64,81,0,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};

bool cmp (int a, int b) {
    return a < b;
}

int main ()
{
    int num[10];
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < 26; j++) {
            if (str == s[j]) {
                num[cnt++] = a[j];
            }
        }
    }

    if (cnt == 0) {
        cout << 0;
        return 0;
    }

    sort(num, num + cnt, cmp);

    for (int i = 0; i < cnt; i++) {
        if (num[i] >= 0 && num[i] <= 9 && i != 0) {
            cout << 0 << num[i];
        }else {
            cout << num[i];
        }
    }
    
    return 0;

}
