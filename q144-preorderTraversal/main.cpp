#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> r;
        stack<TreeNode *> s;

        s.push(root);
        while (!s.empty()) {
            TreeNode* n = s.top();
            s.pop();
            if (n == NULL) {
                continue;
            }

            r.push_back(n->val);
            s.push(n->right);
            s.push(n->left);
        }
        
        return r;
    }
};
