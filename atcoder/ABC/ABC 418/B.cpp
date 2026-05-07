#include <bits/stdc++.h>

int main() {
    std::vector <int> pre(110);
    std::string s;
    std::cin >> s;
    for(int i = 0; i < s.size(); i++) {
        pre[i + 1] = pre[i] + (s[i] == 't');
    }
    double ans = 0.0;
    for(int i = 1; i <= s.size(); i++) {
        if(s[i - 1] != 't') continue;
        for(int j = i + 2; j <= s.size(); j++) {
            if(s[j - 1] == 't')ans = std::max(ans, (pre[j] - pre[i - 1] - 2) / (double)(j - i - 1) * 1.0);
        }
    }
    std::cout << std::fixed << std::setprecision(10) << ans << std::endl;
}