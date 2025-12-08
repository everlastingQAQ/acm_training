#include <iostream>
using namespace std;
int n;
string w, t;
int cnt = 0;

int main ()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w >> t;
        cnt = 0;
        for (int j = 0; j <= (int)t.size() - (int)w.size(); j++) {
            if (t[j] == w[0]) {
                bool is_same = true;
                for (int k = 1; k < w.size(); k++) {
                    if (t[j + k] != w[k]) {
                        is_same = false;
                        break;
                    }else continue;
                }
                if (is_same == true) {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}