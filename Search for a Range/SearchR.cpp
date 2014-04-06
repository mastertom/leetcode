#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ans;
        int notfound[] = {-1,-1};
        int oneele[] = {0,0};
        if (n==0)
        {
            ans.assign(notfound,notfound+2);
            return ans;
        }
        if (n==1)
        {
            if (A[0]==target)
                ans.assign(oneele,oneele+2);
            else
                ans.assign(notfound,notfound+2);
            return ans;
        }
        int left = searchleft(A,n,target);
        int right = searchright(A,n,target);
        if (left==-1)
            ans.assign(notfound,notfound+2);
        else {
            ans.push_back(left);
            ans.push_back(right);
        }   
        return ans;
    }
    int searchleft(int A[], int n, int target)
    {
        if (A[0]>target || A[n-1]<target)
            return -1;
        int start=0,end=n-1,mid;
        while(start<=end)
        {
            mid = (start+end)/2;
            int v = A[mid];
            if (v < target)
                start = mid+1;
            else if (v>target)
                end = mid-1;
            else{
                if (mid == 0)
                    return 0;
                else if (A[mid-1] != target)
                    return mid;
                else
                    end = mid-1;
            }
        }
        if (A[mid]==target)
            return mid;
        else
            return -1;
    }
    int searchright(int A[], int n, int target)
    {
        if (A[0]>target || A[n-1]<target)
            return -1;
        int start=0,end=n-1,mid;
        while(start<=end)
        {
            mid = (start+end)/2;
            int v = A[mid];
            if (v < target)
                start = mid+1;
            else if (v>target)
                end = mid-1;
            else{
                if (mid == n-1)
                    return n-1;
                else if (A[mid+1] != target)
                    return mid;
                else
                    start = mid+1;
            }
        }
        if (A[mid] == target)
            return mid;
        else
            return -1;
    }

};

int main()
{
    Solution SO;
    int A[]= {8,8};
    int n = sizeof(A)/sizeof(int);
    int target = 8;
    vector<int> ans=SO.searchRange(A,n,target);
    cout<<ans[0]<<"  "<<ans[1]<<endl;
}
