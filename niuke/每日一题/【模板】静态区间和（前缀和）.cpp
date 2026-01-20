#include <iostream>
#include <vector>

int main ()
{
    int n, q;
    std::cin >> n >> q;
    std::vector <long long> v(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i];
        s[i] = s[i - 1] + v[i];
    }

    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << s[r] - s[l - 1] << '\n';
    }

    return 0;

}