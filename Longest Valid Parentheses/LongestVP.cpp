#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n<=1) return 0;
        int maxlen=0;
        int last=-1;
        vector <int> stack;
        for (int i=0;i<n;i++)
        {
            if (s[i]=='(')
                stack.push_back(i);
            else 
            {
                if (stack.size()==0)
                    last = i;
                else 
                {
                    stack.pop_back();
                    if (stack.size() == 0)
                        maxlen = max(maxlen,i-last);
                    else
                        maxlen = max(maxlen,i-stack.back());

                }

            }


        }
        return maxlen;
    }
};

int main()
{
    Solution SO;
    string s ="())";
    cout<<s<<endl;
    cout<<SO.longestValidParentheses(s);
}
