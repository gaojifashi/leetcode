#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// struct Item
// {
//     int val;
//     int index;
// };

// bool comp(const Item &it1, const Item &it2)
// {
//     return it1.val < it2.val;
// }

// class Solution {
// public:
//     vector<vector<int> > merge(vector<vector<int> >& intervals) {
//         vector<Item> v;
//         v.reserve(intervals.size() * 2);
//         for (unsigned int i = 0; i < intervals.size(); i++) {
//             for (unsigned int j = 0; j < intervals[i].size(); j++) {
//                 Item it;
//                 it.val = intervals[i][j];
//                 it.index = i;
//                 v.push_back(it);
//             }
//         }

//         std::stable_sort(v.begin(), v.end(), comp);
//         unordered_set<int> s;
//         vector<vector<int> > r;
//         vector<int> x;
//         for (unsigned int i = 0; i < v.size(); i++) {
//             if (s.find(v[i].index) == s.end()) {
//                 if (s.empty() && x.empty()) {
//                     x.push_back(v[i].val);
//                 }

//                 s.insert(v[i].index);
//                 continue;
//             }

//             s.erase(v[i].index);
//             if (s.empty()) {
//                 if (i + 1 < v.size() && v[i].val == v[i + 1].val) {
//                     continue;
//                 }

//                 x.push_back(v[i].val);
//                 r.push_back(x);
//                 x.clear();
//             }
//         }

//         return r;
//     }
// };

class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        if (intervals.empty()) {
            return {};
        }

        sort(intervals.begin(), intervals.end());
        vector<vector<int> > result;
        for (unsigned int i = 0; i < intervals.size(); i++) {
            int L = intervals[i][0];
            int R = intervals[i][1];
            if (result.empty() || result.back()[1] < L) {
                result.push_back({L, R});
            } else {
                result.back()[1] = std::max(result.back()[1], R);
            }
        }

        return result;
    }
};

template<typename T>
void dump(vector<T> &v)
{
    for (unsigned int i = 0; i < v.size(); i++) {
        cout << i << ": " << v[i] << endl;
    }
}

int main(int argc, char *argv[])
{
    Solution s;
    int arr[][2] = {
        {1, 4},
        {4, 5},
    };

    vector<vector<int> > intervals;
    vector<vector<int> > r;

    for (unsigned int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        vector<int> t(&arr[i][0], &arr[i][2]);
        dump(t);
        intervals.push_back(t);
    }

    r = s.merge(intervals);
    for (unsigned int i = 0; i < r.size(); i++) {
        cout << r[i][0] << "," << r[i][1] << endl;
    }

    return 0;
}