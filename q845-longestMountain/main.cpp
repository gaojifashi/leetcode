#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int m = 0;
        for (int i = 0, j = i + 1; i < A.size(); i = j, j = i + 1) {
            int stage = 0;
            for (; j < A.size(); j++) {
                if (A[j] > A[j - 1]) {
                    if (stage == 0) {
                        stage = 1;
                    } else if (stage != 1) {
                        break;
                    }
                } else if (A[j] < A[j - 1]) {
                    if (stage == 1) {
                        stage = 2;
                    } else if (stage != 2) {
                        break;
                    }
                } else {
                    break;
                }
            }

            if (stage == 2) {
                m = std::max(j - i, m);
                j--;
            }
        }

        return m;
    }
};
