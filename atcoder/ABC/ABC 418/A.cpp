#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    if(n < 3) {
        std::cout << "No" << std::endl;
        return 0;
    }   s = s.substr(n - 3);
    if(s == "tea") std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
}