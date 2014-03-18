#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size()<3) return 0;
        sort(num.begin(),num.end());

        int closest=num[0]+num[1]+num[2],sub=abs(closest-target);
        int cur;
        int i,j,k,n=num.size();
        for (i=0;i<n;i++)
        {
            if(i>0 && num[i]==num[i-1]) continue;
            j=i+1;
            k=n-1;
            while(j<k)
            {
               cur =  num[i]+num[j]+num[k];
               if (cur==target)
                   return cur;
               int cursub = abs(cur-target);
               if (cursub<sub)
               {
                   closest = cur;
                   sub = cursub;
               }
               if (cur>target)
                   k--;
               else if (cur<target)
                   j++;
            }
        }
        
        return closest;
    }
};

int main()
{
    Solution SO;
    vector<int> num;
    int n[] = {-1, 2 ,-1 ,3,4,2,1};
    int target = 1;
    num.assign(n,n+sizeof(n)/sizeof(int));
    cout<<SO.threeSumClosest(num,target)<<endl;
    return 0;
}
