#include <iostream>
#include <bits\stdc++.h>
#include <algorithm> 

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        return (str1 + str2 == str2 + str1) ? 
        str1.substr(0, std::gcd(str1.size(), str2.size())) : "";
    }
};

int main() {
    Solution sol;
    std::string str1 = "ABCABC";
    std::string str2 = "ABC";
    std::string result = sol.gcdOfStrings(str1, str2);
    std::cout << "GCD of strings: " << result << std::endl;
    return 0;
}
