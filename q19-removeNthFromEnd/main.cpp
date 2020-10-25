#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *q = head;
        n = n + 1;
        for (ListNode *p = head; p != NULL; p = p->next) {
            if (n == 0) {
                q = q->next;
            } else {
                n--;
            }
        }

        if (q == head) {
            return head->next;
        } else {
            q->next = q->next->next;
            return head;
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    ListNode n(1);
    ListNode *t = s.removeNthFromEnd(&n, 1);
    printf("%p\n", t);

    return 0;
}