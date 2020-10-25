#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     vector<string> restoreIpAddresses(string s) {
//         vector<string> r;
//         size_t n = s.size();
//         if (n > 12 || n < 4) {
//             return r;
//         }

//         // 插空法 C(n - 1, 3), 四个部分 [0, i), [i, j), [j, k), [k, n)
//         // 时间复杂度 O(n ^ 3)
//         for (unsigned int i = 1; i <= n - 3 && (i - 0) <= 3; i++) {
//             for (unsigned int j = i + 1; j <= n - 2 && (j - i) <= 3; j++) {
//                 for (unsigned int k = j + 1; k <= n - 1 && (k - j) <= 3; k++) {
//                     if (n - k > 3) {
//                         continue;
//                     }

//                     string s0 = s.substr(0, i - 0);
//                     int si0 = stoi(s0);
//                     if (si0 > 255 || (s0[0] == '0' && s0.size() != 1)) {
//                         goto exit0;
//                     }

//                     string s1 = s.substr(i, j - i);
//                     int si1 = stoi(s1);
//                     if (si1 > 255 || (s1[0] == '0' && s1.size() != 1)) {
//                         goto exit1;
//                     }

//                     string s2 = s.substr(j, k - j);
//                     int si2 = stoi(s2);
//                     if (si2 > 255 || (s2[0] == '0' && s2.size() != 1)) {
//                         goto exit2;
//                     }

//                     string s3 = s.substr(k, n - k);
//                     int si3 = stoi(s3);
//                     if (si3 > 255 || (s3[0] == '0' && s3.size() != 1)) {
//                         continue;
//                     }

//                     string ip = s0 + "." + s1 + "." + s2 + "." + s3;
//                     r.push_back(ip);
//                 }
//                 exit2:;
//             }
//             exit1:;
//         }

//         exit0:;
//         return r;
//     }
// };

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> r;
        size_t n = s.size();
        if (n > 12 || n < 4) {
            return r;
        }

        // 查表法, 计算 [i, j) 是否能成为ip地址的一部分
        // 时间复杂度 O(n ^ 2)，空间复杂度 O(n ^ 2)
        bool *b = new bool[(n + 1) * (n + 1)];
        for (unsigned int i = 0; i <= n; i++) {
            for (unsigned int j = 0; j <= n; j++) {
                unsigned int pos = i * (n + 1) + j;
                if (i >= j || j - i > 3) {
                    b[pos] = false;
                    continue;
                }

                string ss = s.substr(i, j - i);
                int ssi = stoi(ss);
                if (ssi > 255 || (ss[0] == '0' && ss.size() != 1)) {
                    b[pos] = false;
                } else {
                    b[pos] = true;
                }
            }
        }

        for (unsigned int i = 1; i <= n - 3 && (i - 0) <= 3 && b[i]; i++) {
            for (unsigned int j = i + 1; j <= n - 2 && (j - i) <= 3 && b[i * (n + 1) + j]; j++) {
                for (unsigned int k = j + 1; k <= n - 1 && (k - j) <= 3 && b[j * (n + 1) + k]; k++) {
                    if (n - k > 3 || !b[k * (n + 1) + n]) {
                        continue;
                    }

                    string s0 = s.substr(0, i - 0);
                    string s1 = s.substr(i, j - i);
                    string s2 = s.substr(j, k - j);
                    string s3 = s.substr(k, n - k);

                    string ip = s0 + "." + s1 + "." + s2 + "." + s3;
                    r.push_back(ip);
                }
            }
        }

        return r;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<string> r = s.restoreIpAddresses("1001010");
    for (unsigned int i = 0; i < r.size(); i++) {
        cout << r[i] << endl;
    }

    return 0;
}