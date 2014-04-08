#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        if (n<=1)
            return 0;
        //find start ans end point
        int left,right;
        left = findnextdown(A,n,0);
        right = findnextup(A,n,n-1);
        if (left==-1 || right==-1 || left>=right)
            return 0;
        //find all pairs could store water
        vector<vector<int> > pairs;
        vector<int> pair;
        int i,last;
        //from left to right
        i = left+1;
        last = left;
        while (i<=right)
        {
            if (A[i]>=A[last]){
                pair.clear();
                pair.push_back(last);
                pair.push_back(i);
                pairs.push_back(pair);
                //find next desend i
                i = findnextdown(A,n,i);
                if (i==-1)
                    break;
                last = i++;
            } else
                i++;
        }
        //from right to left
        i = right-1;
        last = right;
        while (i>=left)
        {
            if (A[i]>=A[last]){
                pair.clear();
                pair.push_back(i);
                pair.push_back(last);
                pairs.push_back(pair);
                //find next desend i
                i = findnextup(A,n,i);
                if (i==-1)
                    break;
                last = i--;
            } else
                i--;
        }
        //remove the duplicate of pairs
        sort(pairs.begin(),pairs.end());
        pairs.erase(unique(pairs.begin(),pairs.end()), pairs.end());
        //calculate final water 
        int ans =0;
        for (int i=0;i<pairs.size();i++)
        {
            int l = pairs[i][0];
            int r = pairs[i][1];
            int h = min(A[l],A[r]);
            for (int j=l+1;j<r;j++)
                ans += (h-A[j]);
        }          
        return ans;
    }
    int findnextdown(int A[], int n, int start)
    {
        for (int i =start;i<n-1;i++){
            if (A[i+1]<A[i]){
                return i;
            }
        }
        return -1;
    }
    int findnextup(int A[], int n, int start)
    {
        for (int i =start;i>1;i--){
            if (A[i-1]<A[i]){
                return i;
            }
        }
        return -1;
    }

};

int main()
{
    Solution So;
    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    //int A[] = {0,0,10,0,0,10,0,0,10,0,0};
    int n = sizeof(A)/sizeof(int);
    cout<<So.trap(A,n)<<endl;
}
