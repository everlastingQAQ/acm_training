#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s[0] >= 'a' && s[0] <= 'z') {
            s[0] = toupper(s[0]);
        }
        for (int j = 1; j < s.length(); j++) {
            if (s[j] >= 'A' && s[j] <= 'Z') {
                s[j] = tolower(s[j]);
            }
        }
        cout << s << endl;
    }

    return 0;
}