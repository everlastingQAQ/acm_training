#include <bits/stdc++.h>
using namespace std;
int a[101] = {}, b[101] = {};
int n;

void multiply (int x)
{
    int carry = 0;
    for (int i = 0; i <= 100; i++) {
        a[i] = a[i] * x + carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }
}

void add ()
{
    int carry = 0;
    for (int i = 0; i <= 100; i++) {
        b[i] = b[i] + a[i] + carry;
        carry = b[i] / 10;
        b[i] %= 10;
    }
}

void printing ()
{
    int digit;
    for (int i = 100; i >= 0; i--) {
        if (b[i] != 0) {
            digit = i;
            break;
        }
    }
    for (int i = digit; i >= 0; i--) {
        cout << b[i];
    }
}

int main ()
{
    cin >> n;
    a[0] = 1;
    for (int i = 1; i <= n; i++) {
        multiply(i);
        add();
    }
    printing();
    return 0;
}