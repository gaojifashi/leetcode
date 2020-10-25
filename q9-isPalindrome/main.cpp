#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        unsigned char a[12];
        unsigned n = 0;
        while (x) {
            a[n++] = x % 10;
            x = x / 10;
        }

        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (a[i] == a[j]) {
                continue;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.isPalindrome(0) << endl;
    cout << s.isPalindrome(-321) << endl;
    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(1111) << endl;
    cout << s.isPalindrome(123454321) << endl;

    return 0;
}