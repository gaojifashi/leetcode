#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode *p = head->next;
        head->next = NULL;
        while (p) {
            ListNode *t = head, *k = NULL;
            for (; t != NULL; k = t, t = t->next) {
                if (p->val >= t->val) {
                    continue;
                } else {
                    break;
                }
            }

            if (k == NULL) {
                k = p->next;
                p->next = head;
                head = p;
                p = k;
            } else {
                k->next = p;
                p = p->next;
                k->next->next = t;
            }
        }

        return head;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    ListNode n1(0), n2(1);
    n1.next = &n2;
    ListNode *t = s.insertionSortList(&n1);
    while (t) {
        cout << t->val << endl;
        t = t->next;
    }

    return 0;
}