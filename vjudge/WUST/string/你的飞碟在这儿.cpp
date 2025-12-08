#include <bits/stdc++.h>
using namespace std;

int transform (string s)
{
    int sum = 1;
    for (char c : s) {
        sum *= c - 64;
    }
    sum %= 47;
    return sum;
}

int main ()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (transform(s1) == transform(s2)) {
        cout << "GO";
    }else {
        cout << "STAY";
    }
    return 0;
}