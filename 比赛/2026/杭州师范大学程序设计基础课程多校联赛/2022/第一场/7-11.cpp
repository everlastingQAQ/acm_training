#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;
char ch1, ch2;
int d1, d2;

void solve ()
{
    cin >> ch1 >> ch2 >> d1 >> d2;

    int sum = 0;
    char c1 = 'E', c2 = 'E';     
    if ((ch1 == 'A' || ch1 == 'B' || ch1 == 'C' || ch1 == 'D') && (ch2 == 'A' || ch2 == 'B' || ch2 == 'C' || ch2 == 'D')) {
        if (ch1 == ch2) {
            sum = d1 + d2;
            c1 = ch1;
            c2 = ch2;   
        }else {
            sum = d1 + d2 + 3 * d1 * d2;
            c1 = tolower(ch1);
            c2 = tolower(ch2);
        }
    }else if ((ch1 == 'a' || ch1 == 'b' || ch1 == 'c' || ch1 == 'd') && (ch2 == 'a' || ch2 == 'b' || ch2 == 'c' || ch2 == 'd')) {
        if (ch1 == ch2) {
            sum = d1 + d2;
            c1 = ch1;
            c2 = ch2;
        }else {
            sum = d1 + d2 + d1 * d2;
        }
    }else if ((ch1 == 'a' || ch1 == 'b' || ch1 == 'c' || ch1 == 'd') && (ch2 == 'A' || ch2 == 'B' || ch2 == 'C' || ch2 == 'D')) {
        if (ch1 == tolower(ch2)) {
            sum = d1 + d2;
            c2 = ch2;
        }else {
            sum = d1 + d2 + 2 * d1 * d2;
            c2 = ch2;
        }
    }else if ((ch1 == 'A' || ch1 == 'B' || ch1 == 'C' || ch1 == 'D') && (ch2 == 'a' || ch2 == 'b' || ch2 == 'c' || ch2 == 'd')) {
        if (tolower(ch1) == ch2) {
            sum = d1 + d2;
            c1 = ch1;
        }else {
            sum = d1 + d2 + 2 * d1 * d2;
            c1 = ch1;
        }
    }else if ((ch1 == 'a' || ch1 == 'b' || ch1 == 'c' || ch1 == 'd') && ch2 == 'E') {
        sum = (d1 + d2) * 2;
    }else if ((ch1 == 'A' || ch1 == 'B' || ch1 == 'C' || ch1 == 'D') && ch2 == 'E') {
        sum = (d1 * 2 + d2) * 2; 
        c1 = tolower(ch1);
    }

    cout << sum << endl;
    if (c1 != 'E' && c2 != 'E') {
        if (c1 == c2) {
            cout << c1 << endl;
        }else {
            cout << c1 << ' ' << c2 << endl;
        }
    }else if (c1 != 'E' && c2 == 'E') {
        cout << c1 << endl;
    }else if (c1 == 'E' && c2 != 'E') {
        cout << c2 << endl;
    }
}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
	cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}