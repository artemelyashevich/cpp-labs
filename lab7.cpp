#include <iostream>
#include <string>
#include <algorithm>

std::string convertToBase(int n, int p) {
    if (n == 0) {
        return "0";
    }

    std::string s;
    while (n > 0) {
        int remainder = n % p;
        char digit = (remainder < 10) ? ('0' + remainder) : ('A' + (remainder - 10));
        s.push_back(digit);
        n /= p;
    }

    std::reverse(s.begin(), s.end());

    return s;
}

int main() {
    int n, p;

    std::cout << "Enter a non-negative decimal number: ";
    std::cin >> n;

    std::cout << "Enter the base (2 <= p <= 36): ";
    std::cin >> p;

    std::string result = convertToBase(n, p);

    std::cout << "Resulting representation in base " << p << ": " << result << std::endl;

    return 0;
}