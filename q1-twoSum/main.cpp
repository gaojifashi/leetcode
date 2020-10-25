#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// class Solution {
//     struct Item {
//         int num;
//         int index;
//     };

// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> vctResult;
//         vector<Item> vctItem;
//         vctItem.reserve(nums.size());
//         for (unsigned int i = 0; i < nums.size(); i++) {
//             if (nums[i] <= target) {
//                 Item stItem;
//                 stItem.num = nums[i];
//                 stItem.index = i;
//                 vctItem.push_back(stItem);
//             }
//         }

//         for (unsigned int i = 0; i < vctItem.size() - 1; i++) {
//             Item &it1 = vctItem[i];
//             for (unsigned int j = i + 1; j < vctItem.size(); j++) {
//                 Item &it2 = vctItem[j];
//                 if (it1.num + it2.num == target) {
//                     vctResult.push_back(it1.index);
//                     vctResult.push_back(it2.index);
//                     return vctResult;
//                 }
//             }
//         }

//         return vctResult;
//     }
// };

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> vctResult;
//         for (unsigned int i = 0; i < nums.size() - 1; i++) {
//             for (unsigned int j = i + 1; j < nums.size(); j++) {
//                 if (nums[i] + nums[j] == target) {
//                     vctResult.push_back(i);
//                     vctResult.push_back(j);
//                     return vctResult;
//                 }
//             }
//         }

//         return vctResult;
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> r;
        unordered_map<int, int> ht;

        for (unsigned int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            unordered_map<int, int>::iterator it = ht.find(need);
            if (it != ht.end()) {
                r.push_back(it->second);
                r.push_back(i);
                return r;
            }

            ht[nums[i]] = i;
        }

        return r;
    }
};

int main(int argc, char *argv[])
{
    int arr[] = {-3, 2, 3, 15};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));
    Solution s;
    vector<int> result = s.twoSum(nums, 0);
    for (unsigned int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}