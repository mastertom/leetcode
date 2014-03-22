#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector <string> ans;
        if (n<=0) return ans;
        generateP(0,0,n,"",ans);
        return ans;
    }

    void generateP(int leftcount,int rightcount, int n, string s, vector<string> & ans)
    {
        if (leftcount <rightcount) return;
        if (leftcount==n && rightcount==n) ans.push_back(s);
        if (leftcount==n) {generateP(leftcount,rightcount+1,n,s+')',ans);return;}
        generateP(leftcount,rightcount+1,n,s+')',ans);
        generateP(leftcount+1,rightcount,n,s+'(',ans);
    }
};

int main()
{
    Solution So;
    int n =4;
    vector<string> ans = So.generateParenthesis(n);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
}

/*
 *  when n = 1
 *      ()
 *  when n = 2
 *      (()), ()()
 *  when n = 3
 *      ((())), (()()), (())(), ()(()), ()()()
 */
