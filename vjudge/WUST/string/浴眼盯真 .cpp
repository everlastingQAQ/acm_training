#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int t;
    cin >> t;
    string s1, s2, s3, s4;
    for (int i = 0; i < t; i++) {
        cin >> s1 >> s2 >> s3 >> s4;
        if (s1[0] == 'y' && s2[0] == 'y' && s3 == "ding" && s4 == "zhen") {
            cout << "Yes" << endl;
        }else {
            cout << "No" << endl;
        }
    }
    return 0;
}