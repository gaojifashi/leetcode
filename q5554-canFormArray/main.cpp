#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int> >& pieces) {
        unordered_map<int, int> m;
        for (int i = 0; i < pieces.size(); i++) {
            m[pieces[i][0]] = i;
        }

        int i = 0;
        while (i < arr.size()) {
            if (m.find(arr[i]) == m.end()) {
                return false;
            }

            vector<int> &p = pieces[m[arr[i]]];
            for (int j = 0; j < p.size() && i < arr.size(); j++, i++) {
                if (arr[i] != p[j]) {
                    return false;
                }
            }
        }

        return true;
    }
};
