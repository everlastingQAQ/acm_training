#include <bits/stdc++.h>
using namespace std;
int t, n, m;
const int MAXN = 1001;
string s_in = "freopen(\".in\",\"r\",stdin);";
string s_out = "freopen(\".out\",\"w\",stdout);";

int main ()
{
    string title[4];
    cin >> t >> n >> m;
    
    string s[8];
    int j = 0;
    for (int i = 0; i < m; i++) {
        cin >> title[i];
        s[j] = s_in;
        s[j].insert(9, title[i]);
        j++;
        s[j] = s_out;
        s[j].insert(9, title[i]);
        j++;
    }

    int player[MAXN];
    for (int i = 0; i < n; i++) {
        bool is_general = true;
        bool is_ancestor = false;
        for (int k = 0; k < 2 * m; k++) {
            string temp;
            cin >> temp;
            if (s[k] != temp) {
                is_general = false;
                if (temp[0] == '/' && temp[1] == '/') {
                    is_ancestor = true;
                    continue;
                }
            }
        }
        if (is_general == true) {
            player[i] = 0;
        }else if (is_ancestor == true) {
            player[i] = 1;
        }else {
            player[i] = 2;
        }
    }

    for (int i = 0; i < n; i++) {
        if (player[i] == 0) {
            cout << "PION2202 RP++." << endl;
        }else if (player[i] == 1) {
            cout << "Wrong file operation takes you to your ancestors along with your 3 years' efforts on OI." << endl;
        }else {
            cout << "Good luck and have fun." << endl;
        }
    }

    return 0;
}