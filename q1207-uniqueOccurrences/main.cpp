#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> s;
        for (unsigned int i = 0; i < arr.size(); i++) {
            m[arr[i]]++;
        }

        for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (s.find(it->second) == s.end()) {
                s.insert(it->second);
            } else {
                return false;
            }
        }

        return true;
    }
};
