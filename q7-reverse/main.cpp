#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long int t = x;
        long long int r = 0;
        
        while (t != 0) {
            r = r * 10 + t % 10;
            t = t / 10;
        }

        if (r > INT32_MAX || r < INT32_MIN) {
            return 0;
        } else {
            return r;
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.reverse(0) << endl;
    cout << s.reverse(-321) << endl;
    cout << s.reverse(1999999999) << endl;
    cout << s.reverse(-1999999999) << endl;
    cout << s.reverse(-1999999921) << endl;

    return 0;
}