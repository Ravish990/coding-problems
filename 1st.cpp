#include<iostream>
#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int c = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 || j >= 0 || c) {
            if (i >= 0) c += a[i--] - '0';
            if (j >= 0) c += b[j--] - '0';
            res += c % 2 + '0';
            c /= 2;
        }
        reverse(begin(res), end(res));
        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.addBinary("11", "1") << endl;
    return 0;
}