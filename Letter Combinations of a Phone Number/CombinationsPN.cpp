#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const string dict[] = {"","","abc","def","ghi","jkl","mno","qprs","tuv","wxyz"};
        vector<string> ans;
        vector<string> tmp;
        ans.push_back("");
        for (int i=0;i<digits.length();i++)
        {
            string cur = dict[digits[i]-'0'];
            tmp.clear();
            for (int j=0;j<cur.length();j++)
                for (int k=0;k<ans.size();k++)
                    tmp.push_back(ans[k]+cur[j]);
            if (cur.length()>0)
                ans = tmp;
        }
        return ans;
    }
};

int main()
{
    Solution SO;
    string digits = "23";
    vector <string> ans = SO.letterCombinations(digits);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}
