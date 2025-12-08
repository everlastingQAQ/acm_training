#include <bits/stdc++.h>
using namespace std;
int a = 0, b = 0, c = 0;

int main ()
{
    string s;
    getline(cin, s);
    auto it = s.begin();
    while (it != s.end()) {
        if (*it == 'a' && *(it + 1) == ':') {
            it += 3;
            if (*it >= '0' && *it <= '9') {
                a = *it - '0';
            }else {
                if (*it == 'b') {
                    a = b;
                }else if (*it == 'c') {
                    a = c;
                }
            }
        }else if (*it == 'b' && *(it + 1) == ':') {
            it += 3;
            if (*it >= '0' && *it <= '9') {
                b = *it - '0';
            }else {
                if (*it == 'a') {
                    b = a;
                }else if (*it == 'c') {
                    b = c;
                }
            }
        }else if (*it == 'c' && *(it + 1) == ':') {
            it += 3;
            if (*it >= '0' && *it <= '9') {
                c = *it - '0';
            }else {
                if (*it == 'a') {
                    c = a;
                }else if (*it == 'b') {
                    c = b;
                }
            }
        }else {
            it++;
        }
    }
    cout << a << ' ' << b << ' ' << c;
    return 0;
}