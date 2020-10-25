#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void pathSum(TreeNode* root, int sum, vector<int> &path, vector<vector<int> > &result)
    {
        if (root == NULL) {
            return;
        }

        sum -= root->val;
        path.push_back(root->val);

        // 叶子节点
        if (root->left == NULL && root->right == NULL && sum == 0) {
            result.push_back(path);
        }

        pathSum(root->left, sum, path, result);
        pathSum(root->right, sum, path, result);
        path.pop_back();
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        vector<int> path;
        pathSum(root, sum, path, result);
        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    return 0;
}