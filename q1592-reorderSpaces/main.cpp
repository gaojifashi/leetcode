#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        int total = 0;
        int word = -1;
        bool flag = false;

        for (int pos = 0, next = 0; pos != text.npos; pos = next) {
            if (!flag) {
                word++;
                next = text.find_first_not_of(' ', pos);
                flag = true;
            } else {
                total += (next - pos);
                next = text.find_first_of(' ', pos);
                flag = false;
            }
        }
        
        for (unsigned int i = 0; i < text.size(); i++) {
            if (text.at(i) == ' ') {
                total++;
                if (flag) {
                    word++;
                    flag = false;
                }
            } else {
                flag = true;
            }
        }

        if (flag) {
            word++;
        }

        if (word == 1) {
            return text;
        }

        int per = total / (word - 1);
        string n(text.size(), ' ');
        for (int pos = 0, next = 0; pos != text.npos; pos = next) {
            next = text.find_first_not_of(' ', pos);
            n.replace(pos, n.npos, text.substr(pos, next))
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.reorderSpaces("") << endl;
    cout << s.reorderSpaces("10101") << endl;
    cout << s.reorderSpaces("11001100") << endl;
    cout << s.reorderSpaces("1110110001") << endl;
    cout << s.reorderSpaces("111111") << endl;

    return 0;
}