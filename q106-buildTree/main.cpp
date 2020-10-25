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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, 
        int ii, int ij, int pi, int pj)
    {
        if (ii >= ij) {
            return NULL;
        }
        
        int mid = postorder[pj - 1];
        int offset = 0;
        for (; ii + offset < ij; offset++) {
            if (inorder[ii + offset] == mid) {
                break;
            }
        }

        TreeNode* t = new TreeNode(mid);
        t->left = buildTree(inorder, postorder, ii, ii + offset, pi, pi + offset);
        t->right = buildTree(inorder, postorder, ii + offset + 1, ij, pi + offset, pj - 1);
        return t;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }


};

int main(int argc, char *argv[])
{
    Solution s;

    return 0;
}