#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000000;

int i;
char t;

int find_length (int a)
{
    string a1 = to_string(a);
    return a1.length();
}

int main ()
{
    cin >> i;
    while (cin >> t) {
        int a, b;
        cin >> a >> b;
        if (t == 'a') {
            int lenGth = find_length(a) + find_length(b) + find_length(a + b) + 2;
            cout << a << '+' << b << '=' << a + b << endl;
            cout << lenGth << endl;
        }else if (t == 'b') {
            int lenGth = find_length(a) + find_length(b) + find_length(a - b) + 2;
            cout << a << '-' << b << '=' << a - b << endl;
            cout << lenGth << endl;
        }else if (t == 'c') {
            int lenGth = find_length(a) + find_length(b) + find_length(a * b) + 2;
            cout << a << '*' << b << '=' << a * b << endl;
            cout << lenGth << endl;
        }
        char c = t;
        cin >> t;
        if (t != 'a' && t != 'b' && t != 'c') t = c;
        cin >> a >> b;
        if (t == 'a') {
            int lenGth = find_length(a) + find_length(b) + find_length(a + b) + 2;
            cout << a << '+' << b << '=' << a + b << endl;
            cout << lenGth << endl;
        }else if (t == 'b') {
            int lenGth = find_length(a) + find_length(b) + find_length(a - b) + 2;
            cout << a << '-' << b << '=' << a - b << endl;
            cout << lenGth << endl;
        }else if (t == 'c') {
            int lenGth = find_length(a) + find_length(b) + find_length(a * b) + 2;
            cout << a << '*' << b << '=' << a * b << endl;
            cout << lenGth << endl;
        }
    }
    
    return 0;

}