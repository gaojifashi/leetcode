#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return NULL;
        }

        TreeNode *t = new TreeNode(0);
        TreeNode *l1 = NULL, *l2 = NULL;
        TreeNode *r1 = NULL, *r2 = NULL;
        if (t1 != NULL) {
            t->val += t1->val;
            l1 = t1->left;
            r1 = t1->right;
        }

        if (t2 != NULL) {
            t->val += t2->val;
            l2 = t2->left;
            r2 = t2->right;
        }

        t->left = mergeTrees(l1, l2);
        t->right = mergeTrees(r1, r2);
        return t;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    return 0;
}