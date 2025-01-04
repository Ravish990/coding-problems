#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string intToRoman(int num) {
        std::vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        std::vector<std::string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        std::string result;
        
        for (int i = 0; i < values.size() && num > 0; ++i) {
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    int mao = 1987; 
    std::cout << sol.intToRoman(mao) << std::endl;
    return 0;
}