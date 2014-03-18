#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        string RomanD[] = {"IV","IX","XL","XC","CD","CM"};
        int nD[] = {4,9,40,90,400,900};
        string RomanS[] = {"I","V","X","L","C","D","M"};
        int nS[] = {1,5,10,50,100,500,1000};
        int ans=0;
        int cur=0,n=s.length();
        int d;
        while(cur<n)
        {
            d=0;
            if((n-cur)>1)
            {
                string search = s.substr(cur,2);
                for (int i=0;i<6;i++)
                {
                    if (search == RomanD[i])
                    {
                        ans+= nD[i];
                        cur=cur+2;
                        d=1;
                        break;
                    }
                }
            }
            if(d==0)
            {
                for (int i=0;i<7;i++)
                {
                    string search = s.substr(cur,1);
                    if (search == RomanS[i])
                    {
                        ans+= nS[i];
                        cur=cur+1; 
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution SO;
    string s = "MMMMCMXC";
    cout<<SO.romanToInt(s)<<endl;
    return 0;
}
