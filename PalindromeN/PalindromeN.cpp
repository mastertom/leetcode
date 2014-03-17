#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(0<=x && x<10)
            return true;
        if (x==reverse(x))
            return true;
        else
            return false;
    }
    int reverse(int x) {
        long y=0;
        int last=1,n;
        while (last)
        {
            n = x%10;
            x = x/10;
            if (x==0)
                last=0;
            y = y*10+n;
            //cout<<y<<endl;
        }
        if (y<=INT_MAX && y>=INT_MIN)
            return (int)y;
        return -1;
    }
};

int main()
{
    int x = 1111111117;
    Solution So;
    cout<<So.isPalindrome(x)<<endl;
    cout<<INT_MAX;
    return 0;
}
