#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ans ;
        //preprocess the andidates vector to c vector with no duplicate and number bigger than target
        int n = candidates.size();
        if (n<1) return ans;
        vector<int> c;
        sort(candidates.begin(),candidates.end());
        int last = candidates[0];
        c.push_back(last);
        for (int i=1;i<n;i++)
        {
            if (candidates[i]>target)
                break;
            if (candidates[i]>last)
            {
                last = candidates[i];
                c.push_back(last);
            }
        }
        //recursive function helper
        ans= helper(c,target);
        for (int i =0;i<ans.size();i++)
            ans[i].pop_back();
        return ans;
        
    }
    vector<vector<int> > helper(vector<int> c, int target) 
    {
        vector<vector<int> > ans;
        vector<int> newc;
        if (target == 0){
            newc.clear();
            newc.push_back(-1);
            ans.push_back(newc);
            return ans;
        }

        if (c[0]>target)
            return ans;

        vector<vector<int> > partans;
        int n = c.size();
        int newtarget;
        for (int i=0;i<n;i++)
        {
            int cur = c[i];
            if (cur>target) break;
            newtarget = target - cur;
            newc.clear();
            for (int j=i;j<n;j++)
            {
                newc.push_back(c[j]);
            }
            partans.clear();
            partans = helper(newc,newtarget);
            for (int k=0;k<partans.size();k++)
            {
                partans[k].insert(partans[k].begin(),cur);
                ans.push_back(partans[k]);
            }
        }
        return ans;
    }

};

int main()
{
    Solution SO;
    int c[] = {8,7,4,3};
    vector<int> candidates;
    candidates.assign(c,c+sizeof(c)/sizeof(int));
    int target = 11;
    vector<vector<int> > ans = SO.combinationSum(candidates,target);
    for (int i=0;i<ans.size();i++)
    {
        for (int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}
