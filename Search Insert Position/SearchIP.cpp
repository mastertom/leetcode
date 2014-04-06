#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n==0)
            return 0;
        int i=0;
        while (i<n)
        {
            if (target<=A[i])
                return i;
            i++;
        }
        return n;
    }
};

int main()
{
    Solution SO;
    int A[] = {};
    int n = sizeof(A)/sizeof(int);
    int target = -1;
    cout<<SO.searchInsert(A,n,target)<<endl;
}

