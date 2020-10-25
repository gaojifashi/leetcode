#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int total = 0, cur = 0, last = 0;
        char c = '\0';
        
        for (unsigned int i = 0; i < s.size(); i++) {
            if (s[i] != c) {
                total += std::min(cur, last);
                c = s[i];
                last = cur;
                cur = 1;
            } else {
                cur++;
            }
        }

        total += std::min(cur, last);
        return total;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.countBinarySubstrings("") << endl;
    cout << s.countBinarySubstrings("10101") << endl;
    cout << s.countBinarySubstrings("11001100") << endl;
    cout << s.countBinarySubstrings("1110110001") << endl;
    cout << s.countBinarySubstrings("111111") << endl;

    return 0;
}