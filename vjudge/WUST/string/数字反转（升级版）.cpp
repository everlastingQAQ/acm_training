#include <bits/stdc++.h>
using namespace std;
int t;
string s, s1, s2;

void delete_zero (string &s)
{
    auto it = s.begin();
    while (it != s.end() && *it == '0') {
        it++;
    }
    if (it != s.end()) {
        s.erase(s.begin(), it);
    }
}

void deletezero (string &s)
{   
    auto it = s.end();
    while (it != s.begin()) {
        it--;
        if (*it != '0') {
            it++;
            break;
        }
    }
    if (it != s.begin()) {
        s.erase(it, s.end());
    }
}

void reversing1 (string s)
{
    s1 = s.substr(0, t);
    s2 = s.substr(t + 1, s.size());
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    delete_zero(s1);
    delete_zero(s2);
}

int main ()
{
    char c;
    bool is_float = false;
    bool is_fraction = false;
    bool is_percentage = false;
    while (cin >> c) {
        s.push_back(c);
        if (c == '.') {
            is_float = true;
            t = s.length() - 1;
        }else if (c == '/') {
            is_fraction = true;
            t = s.length() - 1;
        }else if (c == '%') {
            is_percentage = true;
        }
    }

    if (is_float == true) {
        reversing1(s);
        deletezero(s2);
        cout << s1 << '.' << s2;
    }else if (is_fraction == true) {
        reversing1(s);
        cout << s1 << '/' << s2;
    }else if (is_percentage == true) {
        s.erase(s.end() - 1);
        reverse(s.begin(), s.end());
        delete_zero(s);
        cout << s << '%';
    }else {
        reverse(s.begin(), s.end());
        delete_zero(s);
        cout << s;
    }

    return 0;
}