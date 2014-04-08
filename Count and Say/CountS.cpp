#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n==0) return "";
        if (n==1) return "1";
        string lasts = "1";
        int i=1;
        while (i<n)
        {
            string news;
            int len = lasts.length(),j=0,count;
            char num;
            while (j<len)
            {
                count=1;
                num = lasts[j];
                j++;
                while (j<len)
                {
                    if (num == lasts[j])
                    {
                        j++;count++;
                    } else
                        break;
                }
                
                char adding = count + '0';
                news = news + adding + num;
            }
            lasts = news;
            i++;
        }
        return lasts;
    }
};

int main()
{
    Solution SO;
    int n= 5;
    cout<<SO.countAndSay(n)<<endl;
}
