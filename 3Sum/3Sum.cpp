#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;

        if (num.size()<3) return ans;
        sort(num.begin(),num.end());
        
        vector<int> tri;
        int n=num.size(),k,j,sum;
        for (int i=0;i<n;i++)
        {
            if (i>0 && num[i]==num[i-1]) continue;
            j=i+1;
            k=n-1;
            sum=0-num[i];
            while(j<k)
            {
                if(num[k]>(sum-num[j]))
                    k--;
                else if (num[k]<(sum-num[j]))
                    j++;
                else
                {
                    tri.clear();
                    tri.push_back(num[i]);
                    tri.push_back(num[j]);
                    tri.push_back(num[k]);
                    ans.push_back(tri);
                    k--;j++;
                    while(num[k]==num[k+1])
                        k--;
                    while(num[j]==num[j-1])
                        j++;

                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution SO;
    vector<int> num;
    int n[] = {-1, 0 ,1,2,-1,-4 };
    num.assign(n,n+sizeof(n)/sizeof(int));
    vector<vector<int> > ans = SO.threeSum(num);
    for (int i=0;i<ans.size();i++)
    {
        for (int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
