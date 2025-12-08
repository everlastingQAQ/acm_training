#include <bits/stdc++.h>
using namespace std;

string s;
int q;

int main ()
{
    cin >> q >> s;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            string s1;
            cin >> s1;
            s += s1;
            cout << s << endl;
        }else if (t == 2) {
            int a, b;
            cin >> a >> b;
            if (a != 0) {
                s.erase(0, a);
            }
            s.erase(b, s.length() - b);
            cout << s << endl;
        }else if (t == 3) {
            int a;
            cin >> a;
            string s2;
            cin >> s2;
            s.insert(a, s2);
            cout << s << endl;
        }else if (t == 4) {
            string s3;
            cin >> s3;
            int temp = s.find(s3);
            if (temp == string::npos) {
                cout << -1 << endl;
            }else {
                cout << temp << endl;
            }
        }
    }
    return 0;
}