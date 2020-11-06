#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int> >& grid) {
        int sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    continue;
                }

                if (i - 1 < 0 || grid[i - 1][j] == 0)
                    sum++;
                
                if (i + 1 >= grid.size() || grid[i + 1][j] == 0)
                    sum++;
                
                if (j + 1 >= grid[i].size() || grid[i][j + 1] == 0)
                    sum++;

                if (j - 1 < 0 || grid[i][j - 1] == 0)
                    sum++;
            }
        }

        return sum;
    }
};
