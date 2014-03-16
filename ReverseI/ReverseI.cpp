#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
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
        if (y>numeric_limits<int>::max() || y<numeric_limits<int>::min())
            return -1;
        return (int)y;
    }
};

int main()
{
    int num = -114748364;
    Solution So;
    cout<<So.reverse(num)<<endl;
    return 0;
}
