#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        vector<vector<int> > result;
        result.reserve(intervals.size());

        vector<vector<int> >::iterator it = intervals.begin();
        for (; it != intervals.end(); it++) {
            vector<int> &tmp = *it;
            if (newInterval[0] > tmp[1]) {
                result.push_back(tmp);
                continue;
            } else if (newInterval[1] < tmp[0]) {
                break;
            } else {
                newInterval[0] = std::min(tmp[0], newInterval[0]);
                newInterval[1] = std::max(tmp[1], newInterval[1]);
            }
        }

        result.push_back(newInterval);
        result.insert(result.end(), it, intervals.end());
        return result;
    }
};
