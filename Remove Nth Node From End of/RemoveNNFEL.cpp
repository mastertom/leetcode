#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head==NULL)
            return NULL;
        ListNode * todelete = head;
        ListNode * predelete = NULL;
        ListNode * cur = head;
        for(int i=0;i<n-1;i++)
            cur = cur->next;
        while (cur!=NULL)
        {
            if (cur->next!=NULL)
            {
                cur=cur->next;
                predelete=todelete;
                todelete=todelete->next;
            } else
            {
                if (predelete == NULL)
                    return head->next;
                else
                {
                    predelete->next = todelete->next;
                    return head;
                }
            }
        }      
        return head;
    }
};

int main()
{
    Solution So;
    ListNode N1(1);
    ListNode N2(2);
    /*ListNode N3(3);
    ListNode N4(4);
    ListNode N5(5);*/
    N1.next = &N2;
    /*N2.next = &N3;
    N3.next = &N4;
    N4.next = &N5;*/
    ListNode *ans = So.removeNthFromEnd(&N1,2);
    ListNode *h = ans ;
    while ( h != NULL)
    {
        cout<<h->val<<endl;
        h=h->next;
    }
    return 0;
}
