#include <iostream>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k==1) return head;
        int i=0;
        ListNode * cur=head;
        while(cur && i<k-1)
        {
            i++;
            cur=cur->next;
        }
        if (!cur) return head;
        //else revese the first k elements and link it with the rest
        ListNode * rest = reverseKGroup(cur->next,k);
        ListNode * itr = head->next;
        ListNode * tmp;
        cur->next = head; 
        for (int i=1;i<k-1;i++)
        {
            tmp = cur->next;
            cur->next = itr;
            itr = itr->next;
            cur->next->next=tmp;            
        }
        head->next = rest;
        return cur;
    }
};

int main()
{
    Solution SO;
    int k =3;
    ListNode N1(1);
    ListNode N2(2);
    ListNode N3(3);
    ListNode N4(4);
    ListNode N5(5);
    N1.next = &N2;
    N2.next = &N3;
    N3.next = &N4;
    N4.next = &N5;
    ListNode * ans = SO.reverseKGroup(&N1,k);
    while(ans)
    {
        cout<<ans->val<<endl;
        ans=ans->next;
    }
}
