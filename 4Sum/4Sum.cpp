#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ans;
        int n = num.size();
        if (n<4) return ans;
        sort(num.begin(),num.end());

        int i=0,j,k,l=n-1,sum;
        vector<int> four;
        for (i=0;i<n-3;i++)
        {
            if (i>0 && num[i]==num[i-1]) continue;
                for (l=n-1;l>i+2;l--)
                {
                    if (l<n-1 && num[l]==num[l+1]) continue;
                    j=i+1;
                    k=l-1;
                    sum=target-num[i]-num[l];
                    while(j<k)
                    {
                        if(num[k]>(sum-num[j]))
                            k--;
                        else if (num[k]<(sum-num[j]))
                            j++;
                        else
                        {
                            four.clear();
                            four.push_back(num[i]);
                            four.push_back(num[j]);
                            four.push_back(num[k]);
                            four.push_back(num[l]);
                            ans.push_back(four);
                            k--;j++;
                            while(num[k]==num[k+1])
                                k--;
                            while(num[j]==num[j-1])
                                j++;
                        }
                    }
                }
        }


        return ans;
    }
};

int main()
{
    vector<int> num;
    int n[] = {0,0,0,0,0,0,0,0};
    int target = 0;
    num.assign(n,n+sizeof(n)/sizeof(int));
    Solution SO;
    vector<vector<int> > ans=SO.fourSum(num,target);
    for (int i=0;i<ans.size();i++)
    {
        for (int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;

    }
