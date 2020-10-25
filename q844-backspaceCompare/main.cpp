#include <string.h>
#include <iostream>

using namespace std;

#define BUF_LEN 200

class Solution {
public:
    void func(string &s, char *buf, int &len)
    {
        int p = 0;
        for (unsigned int i = 0; i < s.length(); i++) {
            if (s[i] != '#') {
                buf[p++] = s[i];
            } else if (p > 0) {
                p--;
            }
        }

        len = p;
    }

    bool backspaceCompare(string S, string T) {
        char bs[BUF_LEN];
        char bt[BUF_LEN];
        int sl = BUF_LEN;
        int tl = BUF_LEN;
        func(S, bs, sl);
        func(T, bt, tl);

        if (sl != tl) {
            return false;
        } else if (memcmp(bs, bt, sl) != 0) {
            return false;
        } else {
            return true;
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