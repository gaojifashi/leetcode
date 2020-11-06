#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int countBits(int num) {
        int count = 0;
        while (num != 0) {
            count += (num & 1);
            num = num >> 1;
        }

        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {
        map<int, map<int, int> > m;
        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            m[countBits(num)][num]++;
        }

        vector<int> r;
        r.reserve(arr.size());
        for (auto it1 = m.begin(); it1 != m.end(); it1++) {
            map<int, int> &t = it1->second;
            for (auto it2 = t.begin(); it2 != t.end(); it2++) {
                int num = it2->first;
                int count = it2->second;
                r.insert(r.end(), count, num);
            }
        }

        return r;
    }
};
