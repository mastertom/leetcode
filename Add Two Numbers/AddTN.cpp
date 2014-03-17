#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1==NULL)
            return l2;
        if (l2==NULL)
            return l1;

        ListNode *ans = l1;
        ListNode *currans = ans;
        ListNode *currother = l2;
        ListNode *foruse;

        int scanover1 = 0;
        int scanover2 = 0;
        int push = 0;
        int sum;


        while(!scanover1 || !scanover2)
        {
            if(scanover1 || scanover2)
            {
                if(!push)
                    break;
                else
                {
                    sum = currans->val + push;
                    if (sum>=10)
                        push =1;
                    else
                        push =0;
                    currans->val = sum%10;

                    if (currans->next == NULL)
                    {
                        if (push)
                        {
                            currans->next=foruse;
                            foruse->val=1;
                            foruse->next=NULL;
                            break;
                        }
                        break;
                    }
                    currans = currans->next;
                }

            }else
            {
                sum = currans->val + currother->val + push;
                if (sum>=10)
                    push =1;
                else
                    push =0;
                currans->val = sum%10;

                if(currans->next==NULL)
                    scanover1 = 1;
                if(currother->next==NULL)
                    scanover2 = 1;

                if(scanover1 && scanover2 && push==1)
                {
                    currans->next = currother;
                    currans->next->val = push;
                    break;
                }

                if(!scanover1 && !scanover2)
                {
                    currans = currans->next;
                    currother = currother->next;
                    continue;
                }
                if(scanover1 && !scanover2)
                {
                    foruse = currother;
                    currans->next = currother->next;
                    currans = currans->next;
                }
                if(scanover2 && !scanover1)
                {
                    currans = currans->next;
                    foruse = currother;
                    
                }
            }
        }
        return ans;
    }
};

int main()
{
    ListNode l1(1);
    ListNode l1_2(0);
    ListNode l1_3(0);
    l1.next = &(l1_2);
    l1_2.next = &(l1_3);

    ListNode l2(9);
    ListNode l2_2(0);
    ListNode l2_3(0);
    l2.next = &(l2_2);
    l2_2.next = &(l2_3);

    ListNode * ans;
    
    Solution solu;
    ans = solu.addTwoNumbers(&l1,&l2);

    if (ans!=NULL)
    {
        cout<<ans->val;
        while (ans->next != NULL)
        {
            cout<<" "<<ans->next->val;
            ans = ans->next;
        }
    }

    cout<<endl<<"should be: 7 0 8"<<endl;



    return 0;
}
