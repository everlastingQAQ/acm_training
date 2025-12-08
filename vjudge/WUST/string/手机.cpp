#include <bits/stdc++.h>
using namespace std;

int num[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4}; 

int main ()
{
    string s;
    getline (cin, s);

    int cnt = 0;
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            cnt += num[c - 'a'];
        }else {
            cnt++;
        }
    }

    cout << cnt;

    return 0;

}   