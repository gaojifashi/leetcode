#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int bAdd = 0;
        ListNode *r = l1, *p = l1;

        while (l1 != NULL && l2 != NULL) {
            int v = l1->val + l2->val + bAdd;
            if (v >= 10) {
                bAdd = 1;
                v = v - 10;
            } else {
                bAdd = 0;
            }

            p = l1;
            l1->val = v;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 == NULL) {
            p->next = l2;
            l1 = p->next;
        }

        while (l1 != NULL && bAdd) {
            int v = l1->val + bAdd;
            if (v >= 10) {
                bAdd = 1;
                v = v - 10;
            } else {
                bAdd = 0;
            }

            p = l1;
            l1->val = v;
            l1 = l1->next;
        }

        if (bAdd) {
            ListNode *n = new ListNode(1);
            p->next = n;
        }

        return r;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}