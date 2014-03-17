#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        //process p to be a reduced pattern ( combine useless characters)

        int i=0,j=0;
        int isstar=0;
        char starc;
        while (s[i]!='\0')
        {
            //follow the assumption that only p has  '*' and '.'
            if (!isstar && p[j+1]=='*')
            {
                isstar = 1;
                starc = p[j];
                j=j+2;
            }

            if (isstar)
            {
                if (cisMatch(s[i],starc))
                    i++;
                else
                    isstar=0;
                continue;
            }

            if (cisMatch(s[i],p[j]))
            {
                i++;j++;
            }else
                return false;
        }
        if (s[i]=='\0' && p[j]=='\0')
            return true;
        else
            return false;
    }
    bool cisMatch(char a,char b)
    {
        if (a=='.' || b=='.' || a==b)
            return true;
        else
            return false;
    }
};

int main()
{
    char s[] = "aaa";
    char p[] = "a*a";
    Solution So;
    cout<<So.isMatch(s,p)<<endl;
    return 0;
}
