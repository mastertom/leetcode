#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head) return head;
        if (!head->next) return head;
        ListNode begin(0);
        ListNode *before = &begin;
        ListNode *pre = head;
        ListNode *post = head->next;
        while (pre)
        {
            pre->next = post->next;
            post->next = pre;
            before->next = post;

            before = pre;
            pre = before->next;
            if (pre && pre->next)
                post=pre->next;
            else
                break;
        }
        return begin.next;
    }    
};

int main()
{
    Solution SO;
    ListNode L1(1);
    ListNode L2(2);
    ListNode L3(3);
    //ListNode L4(4);
    L1.next = & L2;
    L2.next = & L3;
    //L3.next = & L4;
    ListNode * ans = SO.swapPairs(&L1);
    while (ans != NULL)
    {
        cout <<ans->val<<endl;
        ans=ans->next;
    }

}
