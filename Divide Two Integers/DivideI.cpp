#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = abs((double)dividend);;
        long long b = abs((double)divisor);

        long long ret = 0;
        while (a >= b) {
            cout<<"outer"<<a<<" "<<b<<endl;
            long long c = b;
            for (int i = 0; a >= c; ++i, c <<= 1) {
                cout<<"inner"<<a<<" "<<c<<" "<<ret<<endl;
                a -= c;
                ret += 1 << i;
            }
        }

        return ((dividend^divisor)>>31) ? (-ret) : (ret);
    }
};

int main()
{
    Solution So;
    int divident = INT_MAX;
    int divisor = -1;
    cout<<So.divide(divident,divisor)<<endl;
}
