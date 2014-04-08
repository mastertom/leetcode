#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (n<1)
            return 1;
        int i=0;
        while (i<n)
        {
            if (A[i]>0 && A[i]<=n && A[i] != A[A[i]-1])
            {
                //swap
                int tmp = A[A[i]-1];
                A[A[i]-1] = A[i];
                A[i] = tmp;
            } else
                i++;
        }

        for (i=0; i<n ;i++)
        {
            if (A[i] != i+1)
                return i+1;
        }
        return n+1;
        
    }
};

int main()
{
    Solution SO;
    int A[] = {1,1,1};
    int n = sizeof(A)/sizeof(int);
    cout<<SO.firstMissingPositive(A,n)<<endl;
}
