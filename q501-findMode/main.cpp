#include <iostream>
#include <vector>
#include <unordered_map>
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
    vector<int> findMode(TreeNode* root) {
        vector<int> r;
        if (root == NULL) {
            return r;
        }

        unordered_map<int, int> m;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* t = s.top();
            s.pop();
            if (m.find(t->val) == m.end()) {
                m[t->val] = 1;
            } else {
                m[t->val]++;
            }

            if (t->left) {
                s.push(t->left);
            }

            if (t->right) {
                s.push(t->right);
            }
        }

        int max = 0;
        for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            int value = it->first;
            int count = it->second;
            if (count > max) {
                r.clear();
                r.push_back(value);
                max = count;
            } else if (count == max) {
                r.push_back(value);
            }
        }

        return r;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    return 0;
}