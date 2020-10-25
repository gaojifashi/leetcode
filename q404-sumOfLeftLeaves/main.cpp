#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeaves(root, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root, bool bLeft) {
        if (root == NULL) {
            return 0;
        } else if (root->left == NULL && root->right == NULL) {
            if (bLeft) {
                return root->val;
            } else {
                return 0;
            }
        } else {
            return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    return 0;
}