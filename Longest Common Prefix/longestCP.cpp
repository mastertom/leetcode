#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        if (n==0) return "";
        if (n==1) return strs[0];
        string ans = CommonPrefix(strs[0],strs[1]);
        for (int i=2;i<n;i++)
        {
            string common = CommonPrefix(ans,strs[i]);
            if (common.length()>0)
                ans = common;
            else
                return "";
        }

        return ans;
        
    }
    string CommonPrefix(string a,string b)
    {
        string c = "";
        if (a.length()==0 || b.length()==0)
            return c;
        int l=min(a.length(),b.length());
        for (int i=0;i<l;i++)
        {
            if (a[i]==b[i])
                c.push_back(a[i]);
            else
                break;
        }
        return c;
    }
};

int main()
{
    Solution SO;
    vector<string> strs;
    strs.push_back("a");
    strs.push_back("a");
    strs.push_back("b");
    //strs.push_back("");
    //cout<<SO.CommonPrefix("abcdefr","")<<endl;
    cout<<SO.longestCommonPrefix(strs)<<endl;

}
