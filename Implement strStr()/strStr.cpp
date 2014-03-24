#include<iostream>
using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        //special case to consider
        if (needle==NULL || haystack==NULL)
            return NULL;
        if (needle[0] == '\0')
            return haystack;


        //calculate the help table first;
        int len = 0,pos=2,cnd=0;
        while(needle[len] != '\0')
            len++;
        int * T = new int[len];
        T[0]=-1; T[1]=0;
        while (pos<len)
        {
            if (needle[pos-1]== needle[cnd])
            {
                cnd++;T[pos]=cnd;pos++;
            } else if (cnd>0)
                cnd = T[cnd];
            else
            {
                T[pos]=0;
                pos++;
            }
        }
        //find the index
        int m=0,i=0;
        while (haystack[m+i] != '\0')
        {
            if (haystack[m+i] == needle[i]) {
                if (i==len-1)
                    return haystack+m;
                i++;
            } else
            {
                m = m + i -T[i];
                if (T[i]>-1)
                    i = T[i];
                else
                    i=0;

            }

        }
        delete [] T;
        return NULL;
    }
    
};

int main()
{
    Solution SO;
    char haystack[] = "";
    char needle[] = "";
    char * ans =SO.strStr(haystack,needle);
    if (ans) cout<<ans<<endl;

}
