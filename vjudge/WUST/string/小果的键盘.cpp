#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int j = 0; j < n - 1; j++) {
        if (s[j] == 'V' && s[j + 1] == 'K') {
            cnt++;
        }
    }
    
    string p = s;
    for (int i = 0; i < n; i++) {
        s = p;
        if (s[i] == 'V') {
            s[i] = 'K';
        }else if (s[i] == 'K') {
            s[i] = 'V';
        }

        int t = 0;
        for (int j = 0; j < n - 1; j++) {
            if (s[j] == 'V' && s[j + 1] == 'K') {
                t++;
            }
            if (t > cnt) cnt = t;
        }
    }
    
    cout << cnt;
    return 0;
}