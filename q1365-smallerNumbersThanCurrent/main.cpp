#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result(nums.size(), 0);

        for (unsigned int i = 0; i < nums.size(); i++) {
            for (unsigned int j = 0; j < nums.size(); j++) {
                if (nums[j] < nums[i]) {
                    result[i]++;
                }
            }
        }

        return result;
    }
};
