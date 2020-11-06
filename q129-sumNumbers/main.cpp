#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void preSum(TreeNode* n, int &r, int t) {
        if (n == NULL) {
            return;
        }
        
        t = t * 10 + n->val;
        if (n->left == NULL && n->right == NULL) {
            r = r + t;
            return;
        }

        preSum(n->left, r, t);
        preSum(n->right, r, t);
    }

    int sumNumbers(TreeNode* root) {
        int result = 0;
        preSum(root, result, 0);
        return result;
    }
};
