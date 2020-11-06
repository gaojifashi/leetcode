#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i, j;
        for (i = 1; i < A.size() && A[i] > A[i - 1]; i++) ;
        for (j = i; j < A.size() && A[j] < A[j - 1]; j++) ;

        if (i == 1 || i == j || j != A.size()) {
            return false;
        } else {
            return true;
        }
    }
};
