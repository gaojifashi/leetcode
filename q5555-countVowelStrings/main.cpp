#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 动态转移方程 f(n, k) = f(n, k - 1) + f(n - 1, k)
    // f(n, 0) = 0, f(0, k) = 1
    int countVowelStrings(int n) {
        int *f = new int[(n + 1) * (5 + 1)];
        // 初始化
        for (int i = 1; i <= 5; i++) {
            f[i] = 1;
        }

        for (int i = 0; i <= n; i++) {
            f[i * (5 + 1)] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 5; j++) {
                f[i * (5 + 1) + j] = f[i * (5 + 1) + (j - 1)] + f[(i - 1) * (5 + 1) + j];
            }
        }

        return f[n * (5 + 1) + 5];
    }
};
