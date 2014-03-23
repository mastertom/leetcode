#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n==0) return 0;
        int len=1;
        for (int i=1;i<n;i++)
        {
            if (A[i]!=A[i-1])
                A[len++]=A[i];
        }
        return len;

        
    }
};

int main()
{
    Solution SO;
    int A[]={1,1,2,2,4,4,4,5};
    int n= sizeof(A)/sizeof(int);
    SO.removeDuplicates(A,n);
}
