#include <iostream>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        //find the pivot in log(n)
        if (n<=1)
            return binarysearch(A,0,n-1,target);
        if (A[0] < A[n-1])
            return binarysearch(A,0,n-1,target);
        int start=0,end=n-1,mid;
        while (start<end)
        {
            mid = (start+end)/2;
            if (start==mid)
                break;
            if(A[start]>A[mid])
                end = mid;
            else
                start = mid;
        }
        int pivot = mid+1;
        //find the index in log(n)
        if (target == A[pivot])
            return pivot;
        if (target >= A[0])
            return binarysearch(A,0,pivot-1,target);
        return binarysearch(A,pivot,n-1,target);
    }
    int binarysearch(int A[], int start, int end,int target)
    {
        if (start>end) return -1;
        if (target < A[start] || target > A[end])
            return -1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            int midValue =  A[mid];
            if (target == midValue)
                return mid;
            else if (target < midValue)
                end = mid-1;
            else
                start = mid+1;
        }
        return -1;
    }
};

int main()
{
    Solution SO;
    int A[] = {1,0};
    int n = sizeof(A)/sizeof(int);
    int target =0;
    cout<< SO.search(A,n,target)<<endl;
}
