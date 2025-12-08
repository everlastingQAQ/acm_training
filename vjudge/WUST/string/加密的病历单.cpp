#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    for (auto &c : s) {
        if (islower(c)) {
            c = toupper(c);
        }else if (isupper(c)) {
            c = tolower(c);
        }
        
        if (c == 'x') {
            c = 'a';
        }else if (c == 'y') {
            c = 'b';
        }else if (c == 'z') {
            c = 'c';
        }else if (c == 'X') {
            c = 'A';
        }else if (c == 'Y') {
            c = 'B';
        }else if (c == 'Z') {
            c = 'C';
        }else {
            c += 3;
        }
    }
    cout << s;
    return 0;
}