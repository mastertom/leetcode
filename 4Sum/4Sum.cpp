#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ans;
        return ans;
    }
};

int main()
{
    vector<int> num;
    int n[] = {1,0,-1,0,-2,2};
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
