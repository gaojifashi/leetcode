#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    inline bool IsInclude(vector<int> &a, vector<int> &b) {
        return (a[0] <= b[0] && a[1] >= b[1]);
    }

    void dump(vector<vector<int> >& clips) {
        for (unsigned int i = 0; i < clips.size(); i++) {
            printf("index: %u, begin: %d, end: %d", i, clips[i][0], clips[i][1]);
        }
    }

    int videoStitching(vector<vector<int> >& clips, int T) {
        if (T <= 0) {
            return 0;
        } else if (clips.empty()) {
            return -1;
        }

        std::sort(clips.begin(), clips.end());
        
        // 去除被包含的子区间
        unsigned int p = 0;
        for (unsigned int i = p + 1; i < clips.size(); i++) {
            vector<int> &a = clips[p];
            vector<int> &b = clips[i];
            if (IsInclude(b, a)) {
                a = b;
            } else if (!IsInclude(a, b)) {
                p++;
            }
        }
        
        clips.resize(p);

        // 计算最少片段数
        vector<int> FT(101, 0);
        p = 0;
        for (unsigned int i = 0; i < clips.size() && p < T; i++) {
            // 针对每一个片段c
            int begin = clips[i][0];
            int end = clips[i][1];
            if (begin > p) {
                // 片段不连续，肯定拼凑不了完整的视频
                return -1;
            } else if (end >= T) {
                end = T;
            }

            // 重叠部分最小值
            int min = *std::min_element(FT.begin() + begin, FT.begin() + p);
            for (unsigned int j = p + 1; j <= end && j < FT.size(); j++) {
                FT[j] = min + 1;
            }
            
            p = end;
        }

        if (p < T) {
            return -1;
        } else {
            return FT[p];
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;


    return 0;
}