#include <iostream>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        int i=0,negetive=0;
        long long ans=0;

        //delete space
        while(str[i]==' ')
        {i++;}
        //minus simbol
        if(str[i]=='-'){
            i++;negetive=1;
        }else if(str[i]=='+')
            i++;
        //extract number
        while(str[i]!='\0' && str[i]>='0' && str[i]<='9')
        {   
            ans = ans*10 + (int)(str[i]-'0');
            i++;
        }
        //combine the minus simbol
        if(negetive)
            ans=-ans;

        if (ans<=2147483647 && ans>=-2147483648)
            return (int) ans;
        else if (negetive)
            return -2147483648;
        else return 2147483647;       
    }
};

int main()
{
    char str[] = "2147483648";
    Solution So;
    cout<<So.atoi(str)<<endl;

    return 0;
}
