#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
    
string a1, a2;

void solve ()
{
    cin >> a1 >> a2;
    if (a1.find('.') == string::npos || a2.find('.') == string::npos) {
        cout << "ni shi dui de" << '\n';
        return;
    }
    string s1 = a1.substr(0, a1.find('.'));
    string s2 = a2.substr(0, a2.find('.'));

    if (s1.size() != s2.size()) {
        cout << "ni shi dui de" << '\n';
        return;
    }
    
    int found1 = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] < s2[i]) {
            found1 = 1;
            break;
        }else if (s1[i] > s2[i]) {
            found1 = 2;
            break;
        }
    }

    if (found1 != 0) {
        cout << "ni shi dui de" << '\n';
        return;
    }

    string ss1 = a1.substr(a1.find('.') + 1, a1.size() - a1.find('.'));
    string ss2 = a2.substr(a2.find('.') + 1, a2.size() - a2.find('.'));

    int found2 = 0;//normal compare
    for (int i = 0; i < min(ss1.size(), ss2.size()); i++) {
        if (ss1[i] < ss2[i]) {
            found2 = 1;
            break;
        }else if (ss1[i] > ss2[i]) {
            found2 = 2;
            break;
        }
    }

    int found3 = 0;//require compare
    string t1; int index = 0;//remove 0 from front
    while (index < ss1.size()) {
        if (ss1[index] != '0') {
            break;
        }
        index++;
    }
    t1 = ss1.substr(index, ss1.size() - index);

    string t2; index = 0;
    while (index < ss2.size()) {
        if (ss2[index] != '0') {
            break;
        }
        index++;
    }
    t2 = ss2.substr(index, ss2.size() - index);

    if (t1.size() < t2.size()) {
        found3 = 1;
    }else if (t1.size() > t2.size()) {
        found3 = 2;
    }else {
        for (int i = 0; i < t1.size(); i++) {
            if (t1[i] < t2[i]) {
                found3 = 1;
                break;
            }else if (t1[i] > t2[i]) {
                found3 = 2;
                break;
            }
        }
    }

    if (found2 == found3) {
        cout << "ni shi dui de" << '\n';
    }else if (found2 == 0 && found3 == 1) {
        cout << "ni cuo le, ying gai shi <" << '\n';
    }else if (found2 == 0 && found3 == 2) {
        cout << "ni cuo le, ying gai shi >" << '\n';
    }else if (found2 == 1 && found3 == 0) {
        cout << "ni cuo le, ying gai shi =" << '\n';
    }else if (found2 == 1 && found3 == 2) {
        cout << "ni cuo le, ying gai shi >" << '\n';
    }else if (found2 == 2 && found3 == 0) {
        cout << "ni cuo le, ying gai shi =" << '\n';
    }else if (found2 == 2 && found3 == 1) {
        cout << "ni cuo le, ying gai shi <" << '\n';
    }
}
 
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}