#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if (n==0) return NULL;
        if (n==1) return lists[0];
        int half = n/2;
        vector<ListNode *> newlists;
        for (int i=0;i<half;i++)
        {
            newlists.push_back(lists[lists.size()-1]);
            lists.pop_back();
        }
        return mergetwo(mergeKLists(lists),mergeKLists(newlists));
    }
    ListNode *mergetwo(ListNode * l1,ListNode * l2)
    {
        if (l1==NULL)
            return l2;
        if (l2==NULL)
            return l1;
        ListNode *head;
        ListNode *cur;
        if (l1->val <= l2->val)
        {   head = l1;l1=l1->next;}
        else
        {   head = l2;l2=l2->next;}
        cur = head;
        while (l1!=NULL && l2!=NULL)
        {
            if (l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 =l2->next;
            }
            cur = cur->next;
        }
        if(l1==NULL)
            cur->next = l2;
        if(l2==NULL)
            cur->next = l1;
        return head;
    }
};

int main()
{
    Solution So;
    vector<ListNode *> lists;
    ListNode * ans;
    ListNode L11(1);
    ListNode L12(3);
    ListNode L13(5);
    L11.next = &L12;
    L12.next = &L13;
    L13.next = NULL;
    ListNode L21(2);
    ListNode L22(4);
    ListNode L23(6);
    L21.next = &L22;
    L22.next = &L23;
    L23.next = NULL;
    ListNode L31(0);
    ListNode L32(10);
    L31.next = &L32;
    L32.next = NULL;
    lists.push_back(&L11);
    lists.push_back(&L21);
    lists.push_back(&L31);
    ans = So.mergeKLists(lists);
    //ans = So.mergetwo(&L11,NULL);
    while (ans!=NULL)
    {
        cout<<ans->val<<"  "<<endl;
        ans=ans->next;
    }
    return 0;
}
