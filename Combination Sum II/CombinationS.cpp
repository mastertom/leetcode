#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > result; 
        vector<int> intermediate;
        helper(num, target, 0, intermediate, result);
        return result;        
    }
    void helper(vector<int>& num, int gap, int start, vector<int>& intermediate,
            vector<vector<int> > &result) 
    {
        if (gap==0)
        {
            result.push_back(intermediate);
            return;
        }
        int i=start;
        while (i<num.size())
        {
            int cur=num[i];
            if (gap<cur)
                return;
            intermediate.push_back(cur);
            helper(num,gap-cur,i+1,intermediate,result);
            intermediate.pop_back();
            i++;
            while (i<num.size() && num[i]==cur)
                i++;
        }

    }
};

int main()
{
    Solution SO;
    int set[] = {10};
    int target = 8;
    vector<int> num;
    num.assign(set,set+sizeof(set)/sizeof(int));
    vector<vector<int> >ans = SO.combinationSum2(num,target);
    for (int i=0;i<ans.size();i++)
    {
        for (int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}
