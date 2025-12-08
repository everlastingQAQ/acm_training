#include <bits/stdc++.h>
using namespace std;

int cnt[26]={}; 

bool cmp (int a, int b) {
    return a > b;
}

int main ()
{
    string s;
    cin >> s;
    
    for (char c : s) {
        cnt[c - 'a']++;
    }

    sort(cnt, cnt + 26, cmp);

    int t;
    for (int i = 25; i >= 0; i--) {
        if (cnt[i] != 0) {
            t = cnt[i];
            break;  
        }
    }

    int num = cnt[0] - t;

    if (num == 0 || num == 1) {
        cout << "No Answer" << endl << 0;
        return 0;
    }

    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            cout << "No Answer" << endl << 0;
            return 0;
        }
    }

    cout << "Lucky Word" << endl << num;
    
    return 0;

}