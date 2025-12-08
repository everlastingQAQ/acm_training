#include <bits/stdc++.h>
using namespace std;
const int MAXN = 101;

struct score {
    int p;
    string name;
};

int main ()
{
    score a[MAXN]; 
    int n;
    cin >> n;
    
    int b;
    string name;
    cin >> b >> name;
    a[0].p = b;
    a[0].name = name;

    int max = b;
    int t = 0;
    for (int i = 1; i < n; i++) {
        cin >> b >> name;
        a[i].p = b;
        a[i].name = name;
        if (b > max) {
            max = b;
            t = i;
        }
    }
    cout << a[t].name;
    return 0;
}