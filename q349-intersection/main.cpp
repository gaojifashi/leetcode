#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> r;
        if (nums1.size() < nums2.size()) {
            s.insert(nums1.begin(), nums1.end());
            for (unsigned int i = 0; i < nums2.size(); i++) {
                unordered_set<int>::iterator it = s.find(nums2[i]);
                if (it != s.end()) {
                    r.push_back(*it);
                    s.erase(it);
                }
            }
        } else {
            s.insert(nums2.begin(), nums2.end());
            for (unsigned int i = 0; i < nums1.size(); i++) {
                unordered_set<int>::iterator it = s.find(nums1[i]);
                if (it != s.end()) {
                    r.push_back(*it);
                    s.erase(it);
                }
            }
        }

        return r;
    }
};

int main(int argc, char *argv[])
{
    int arr1[] = {4,9,5};
    int arr2[] = {9,4,9,8,4};
    vector<int> nums1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
    vector<int> nums2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
    Solution s;
    vector<int> result = s.intersection(nums1, nums2);
    for (unsigned int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}